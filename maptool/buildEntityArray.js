const ROOM_WIDTH_PX = 128 - 16;
const ROOM_HEIGHT_PX = 64;

function getRoomAt(mapX, mapY) {
    const roomX = Math.floor(mapX / ROOM_WIDTH_PX);
    const roomY = Math.floor(mapY / ROOM_HEIGHT_PX);

    return {
        roomX,
        roomY,
        roomPxX: roomX * ROOM_WIDTH_PX,
        roomPxY: roomY * ROOM_HEIGHT_PX
    };
}

// for TELEPORTER, dig in and find the DEST_ROOM_X or DEST_ROOM_Y
// for CHEST, dig in and find out what the chest contains
function getPropertyValue(props, propName) {
    const prop = props && props.find(p => p.name === propName);
    return prop && prop.value;
}

// combine the entity type plus its encoded id into one value
// for most entities, the encoded id is zero, it's only used by a few
// entity types to sneak in a bit more info (what's inside a chest for example)
function getTypeInt(entity) {
    const typeInt = entity.type | (entity.miscValue << 5);

    return `miscAndEntityType(${entity.miscValue}, ${entity.typeName})`;
}

function getTeleporterArrayData(name, teleporters) {
    const dataStringForTeleporters = `const uint8_t PROGMEM ${name}_teleporters[] = {\n    // dest x, dest y (in rooms)`;

    const teleporterData = teleporters.reduce((building, teleporter) => {
        return building + `\n    ${teleporter.destX}, ${teleporter.destY},`;
    }, "");

    return dataStringForTeleporters + teleporterData + "\n};";
}

/**
 * store an entity's location (x and y) in one byte. This only
 * allows 16 values for x and 16 for y, so the stored values get unpacked as:
 *
 * actual x = packed x * 8; // [0, 120]
 * actual y = packed y * 4; // [0, 60]
 */
function getXYInOneByte(rawX, rawY) {
    packedX = Math.min(15, Math.round(rawX / 8));
    packedY = Math.min(15, Math.round(rawY / 4));

    // let C++ pack the bytes together, that way can look
    // at the entity in the game's code and easily see its location
    return `xy(${packedX * 8}, ${packedY * 4})`;
}

function getRoomArrayData(
    name,
    objectLayer,
    mapWidthInTiles,
    mapHeightInTiles,
    mapWidthInRooms,
    mapHeightInRooms
) {
    const { objects } = objectLayer;
    let rooms = [[]];
    const teleporters = [];

    // the entity type can also encode other data
    // teleporters: an index into the teleporters array to find out where to teleport to
    // chest: an entity type id that indicates what is in the chest (must be [0,8))
    function getMiscValue(obj) {
        if (obj.type === "TELEPORTER") {
            return teleporters.length;
        }

        if (obj.type === "CHEST" || obj.type === "POT") {
            const containedTypeName = getPropertyValue(
                obj.properties,
                "CONTAINED_TYPE"
            );
            return containedTypeName || 0;
        }

        const miscString = getPropertyValue(obj.properties, "MISC");
        return miscString || 0;
    }

    objects.forEach((obj, i) => {
        const { roomX, roomY, roomPxX, roomPxY } = getRoomAt(obj.x, obj.y);
        const entityX = obj.x - roomPxX;
        const entityY = obj.y - roomPxY;

        rooms[roomX] = rooms[roomX] || [];
        rooms[roomX][roomY] = rooms[roomX][roomY] || [];
        rooms[roomX][roomY].push({
            x: entityX,
            y: entityY,
            typeName: obj.type,
            miscValue: getMiscValue(obj)
        });

        if (obj.type === "TELEPORTER") {
            teleporters.push({
                id: teleporters.length,
                destX: getPropertyValue(obj.properties, "DEST_ROOM_X"),
                destY: getPropertyValue(obj.properties, "DEST_ROOM_Y")
            });
        }
    });

    const roomArrayStrings = [];

    for (let rx = 0; rx < mapWidthInRooms; ++rx) {
        for (let ry = 0; ry < mapHeightInRooms; ++ry) {
            const entities = (rooms[rx] || [])[ry] || [];

            // skip empty rooms, instead they will all use
            // the same empty_room array
            if (entities.length === 0) {
                continue;
            }

            const entityData = entities.reduce((dataStr, e, ind) => {
                let result = "";
                if (dataStr) {
                    result += "\n";
                }
                result += `    // entity ${ind}\n`;
                result += `    ${getTypeInt(e)},\n`;
                result += `    ${getXYInOneByte(e.x, e.y)},\n`;

                return dataStr + result;
            }, "");

            const roomVariableName = `${name}_room${rx}_${ry}`;
            let dataStringForRoom = `const uint8_t PROGMEM ${roomVariableName}[] = {\n`;
            dataStringForRoom += `    ${entities.length}${
                entities.length ? "," : ""
            } // number of entities\n${entities.length ? "\n" : ""}`;
            dataStringForRoom += entityData;
            dataStringForRoom += "};\n\n";

            roomArrayStrings.push(dataStringForRoom);
        }
    }

    const teleporterArrayString = getTeleporterArrayData(name, teleporters);

    const roomArrayData =
        roomArrayStrings.join("\n\n") + teleporterArrayString + "\n\n" + "\n\n";

    return { roomArrayData, rooms };
}

function getRowArrayData(name, mapWidthInRooms, mapHeightInRooms, rooms) {
    const rowArrays = new Array(mapHeightInRooms)
        .fill(0, 0, mapHeightInRooms)
        .map((_, ry) => {
            const roomPointers = new Array(mapWidthInRooms)
                .fill(0, 0, mapWidthInRooms)
                .map((_, rx) => {
                    const entities = (rooms[rx] || [])[ry] || [];
                    if (entities.length === 0) {
                        return "empty_room";
                    } else {
                        return `${name}_room${rx}_${ry}`;
                    }
                });

            let arrayStr = `const uint8_t * const PROGMEM ${name}_row${ry}[${
                roomPointers.length
            }] = {\n`;
            arrayStr += "    " + roomPointers.join(",\n    ") + "\n";
            arrayStr += "};\n";

            return arrayStr;
        });

    return rowArrays.join("\n\n");
}

function getMapArrayData(name, mapHeightInRooms) {
    const rowPointers = new Array(mapHeightInRooms)
        .fill(0, 0, mapHeightInRooms)
        .map((_, ry) => {
            return `${name}_row${ry}`;
        });

    let mapArrayStr = `const uint8_t * const* const PROGMEM ${name}_entities[${
        rowPointers.length
    }] = {\n`;
    mapArrayStr += "    " + rowPointers.join(",\n    ") + "\n";
    mapArrayStr += "};\n";

    return mapArrayStr;
}

module.exports = function buildEntityArrays(
    name,
    objectLayer,
    mapWidthInTiles,
    mapHeightInTiles,
    tileSize
) {
    const tilesPerRow = ROOM_WIDTH_PX / tileSize;
    const tilesPerColumn = ROOM_HEIGHT_PX / tileSize;

    const mapWidthInRooms = mapWidthInTiles / tilesPerRow;
    const mapHeightInRooms = mapHeightInTiles / tilesPerColumn;

    const { roomArrayData, rooms } = getRoomArrayData(
        name,
        objectLayer,
        mapWidthInTiles,
        mapHeightInTiles,
        mapWidthInRooms,
        mapHeightInRooms
    );

    const rowArrayData = getRowArrayData(
        name,
        mapWidthInRooms,
        mapHeightInRooms,
        rooms
    );

    const mapArrayData = getMapArrayData(name, mapHeightInRooms);

    const twoLines = "\n\n";
    return roomArrayData + twoLines + rowArrayData + twoLines + mapArrayData;
};
