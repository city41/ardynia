const ROOM_WIDTH_PX = 128 - 16;
const ROOM_HEIGHT_PX = 64;

const EntityTypes = {
    UNSET: -1,
    SWORD: 0,
    BOOMERANG: 1,
    BOMB: 2,
    CANDLE: 3,
    KEY: 4,
    HEART: 5,
    CHEST: 6,
    BLOB: 7,
    SPIKE: 8,
    ENEMY3: 9,
    BLOB_MOTHER: 10,
    NEMESIS: 11,
    TELEPORTER: 12,
    LOCK: 13,
    PROJECTILE: 14,
    EXPLOSION: 15,
    SECRET_WALL: 16
};

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

// for TELEPORTER and SECRET_WALL, dig in and find the DEST_ROOM_X or DEST_ROOM_Y
// for CHEST, dig in and find out what the chest contains
function getPropertyValue(props, propName) {
    return props && props.find(p => p.name === propName).value;
}

// combine the entity type plus its encoded id into one value
// for most entities, the encoded id is zero, it's only used by a few
// entity types to sneak in a bit more info (what's inside a chest for example)
function getTypeInt(entity) {
    const typeInt = entity.type | (entity.encodedId << 5);

    return "0x" + typeInt.toString(16);
}

function getTeleporterArrayData(name, teleporters) {
    const dataStringForTeleporters = `const uint8_t PROGMEM ${name}_teleporters[] = {\n    // dest x, dest y (in rooms)`;

    const teleporterData = teleporters.reduce((building, teleporter) => {
        return building + `\n    ${teleporter.destX}, ${teleporter.destY},`;
    }, "");

    return dataStringForTeleporters + teleporterData + "\n};";
}

function getBumperArrayData(name, bumpers) {
    const dataStringForBumpers = `const uint8_t PROGMEM ${name}_bumpers[] = {\n    // width, height`;

    const bumperData = bumpers.reduce((building, bumper) => {
        return building + `\n    ${bumper.width}, ${bumper.height},`;
    }, "");

    return dataStringForBumpers + bumperData + "\n};";
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
    const bumpers = [];

    function getBumperIdWithSize(width, height) {
        const bumper = bumpers.find(
            b =>
                b.width === Math.floor(width) && b.height === Math.floor(height)
        );

        if (bumper) {
            return bumper.id;
        }

        return null;
    }

    // the entity type can also encode other data
    // teleporters: an index into the teleporters array to find out where to teleport to
    // bumpers: an index into the bumpers array to find out how big the bumper is
    // chest: an entity type id that indicates what is in the chest (must be [0,8))
    //
    // TODO: bumpers can share indices if they are the same size, this is a decent size win
    function getEncodedId(obj) {
        if (obj.type === "TELEPORTER" || obj.type === "SECRET_WALL") {
            return teleporters.length;
        }
        if (obj.type === "BUMPER") {
            const encodedId = getBumperIdWithSize(obj.width, obj.height);
            if (encodedId === null) {
                throw new Error("failed to get an encoded id for a bumper");
            }
            return encodedId;
        }

        if (obj.type === "CHEST") {
            const containedTypeName = getPropertyValue(
                obj.properties,
                "CONTAINED_TYPE"
            );
            return EntityTypes[containedTypeName];
        }

        return 0;
    }

    objects.forEach((obj, i) => {
        const { roomX, roomY, roomPxX, roomPxY } = getRoomAt(obj.x, obj.y);
        const entityX = obj.x - roomPxX;
        const entityY = obj.y - roomPxY;
        const type = EntityTypes[obj.type];

        if (obj.type === "BUMPER") {
            if (getBumperIdWithSize(obj.width, obj.height) === null) {
                bumpers.push({
                    id: bumpers.length,
                    width: Math.floor(obj.width),
                    height: Math.floor(obj.height)
                });
            }
        }

        rooms[roomX] = rooms[roomX] || [];
        rooms[roomX][roomY] = rooms[roomX][roomY] || [];
        rooms[roomX][roomY].push({
            x: entityX,
            y: entityY,
            type,
            typeName: obj.type,
            encodedId: getEncodedId(obj)
        });

        if (obj.type === "TELEPORTER" || obj.type === "SECRET_WALL") {
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
            const entityData = entities.reduce((dataStr, e, ind) => {
                let result = "";
                if (dataStr) {
                    result += "\n";
                }
                result += `    // entity ${ind}, ${e.typeName}\n`;
                result += `    ${getTypeInt(e)},\n`;

                result += `    ${Math.floor(e.x)}, //x\n    ${Math.floor(e.y)}${
                    ind < entities.length - 1 ? "," : " "
                } //y\n`;

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

    if (bumpers.length > 7) {
        throw new Error(
            "over bumper limit of 7, have " + bumpers.length + " bumpers"
        );
    } else {
        console.log("number of bumpers for", name, bumpers.length);
    }

    const teleporterArrayString = getTeleporterArrayData(name, teleporters);
    const bumperArrayString = getBumperArrayData(name, bumpers);

    return (
        roomArrayStrings.join("\n\n") +
        teleporterArrayString +
        "\n\n" +
        "\n\n" +
        bumperArrayString
    );
}

function getRowArrayData(name, mapWidthInRooms, mapHeightInRooms) {
    const rowArrays = new Array(mapHeightInRooms)
        .fill(0, 0, mapHeightInRooms)
        .map((_, ry) => {
            const roomPointers = new Array(mapWidthInRooms)
                .fill(0, 0, mapWidthInRooms)
                .map((_, rx) => {
                    return `${name}_room${rx}_${ry}`;
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

    let mapArrayStr = `const uint8_t ** const PROGMEM ${name}_entities[${
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

    const roomArrayData = getRoomArrayData(
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
        mapHeightInRooms
    );

    const mapArrayData = getMapArrayData(name, mapHeightInRooms);

    const twoLines = "\n\n";
    return roomArrayData + twoLines + rowArrayData + twoLines + mapArrayData;
};
