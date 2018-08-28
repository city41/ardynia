const ROOM_WIDTH_PX = 128 - 16;
const ROOM_HEIGHT_PX = 64;

const EntityTypes = {
    UNSET: -1,
    SWORD: 0,
    BLOB: 1,
    OVERWORLD_DOOR: 2,
    BUMPER: 3,
    BOOMERANG: 4,
    BOMB: 5,
    CANDLE: 6,
    CHEST: 7,
    KEY: 8,
    LOCK: 9,
    BUSH: 10,
    ENEMY2: 11,
    ENEMY3: 12,
    ENEMY4: 13,
    ENEMY5: 14,
    ENEMY6: 15,
    BOSS1: 16,
    BOSS2: 17,
    BOSS3: 18,
    HEART: 19,
    HEART_CONTAINER: 20
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

// for OVERWORLD_DOOR, dig in and find the DEST_ROOM_X or DEST_ROOM_Y
function getPropertyInt(props, propName) {
    return props.find(p => p.name === propName).value;
}

// for non-OVERWORLD_DOOR, just return the type directly, for doors,
// encode the door id into the type
function getTypeInt(entity) {
    const typeInt = entity.type | (entity.encodedId << 5);

    return "0x" + typeInt.toString(16);
}

function getDoorArrayData(name, doors) {
    const dataStringForDoors = `const uint8_t PROGMEM ${name}_doors[] = {\n    // dest x, dest y (in rooms)`;

    const doorData = doors.reduce((building, door) => {
        return building + `\n    ${door.destX}, ${door.destY},`;
    }, "");

    return dataStringForDoors + doorData + "\n};";
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
    const doors = [];
    const bumpers = [];

    objects.forEach((obj, i) => {
        const { roomX, roomY, roomPxX, roomPxY } = getRoomAt(obj.x, obj.y);
        const entityX = obj.x - roomPxX;
        const entityY = obj.y - roomPxY;
        const type = EntityTypes[obj.type];

        rooms[roomX] = rooms[roomX] || [];
        rooms[roomX][roomY] = rooms[roomX][roomY] || [];
        rooms[roomX][roomY].push({
            x: entityX,
            y: entityY,
            type,
            typeName: obj.type,
            encodedId:
                obj.type === "OVERWORLD_DOOR"
                    ? doors.length
                    : obj.type === "BUMPER"
                        ? bumpers.length
                        : 0
        });

        if (obj.type === "OVERWORLD_DOOR") {
            doors.push({
                id: doors.length,
                destX: getPropertyInt(obj.properties, "DEST_ROOM_X"),
                destY: getPropertyInt(obj.properties, "DEST_ROOM_Y")
            });
        } else if (obj.type === "BUMPER") {
            bumpers.push({
                id: bumpers.length,
                width: Math.floor(obj.width),
                height: Math.floor(obj.height)
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

    const doorArrayString = getDoorArrayData(name, doors);
    const bumperArrayString = getBumperArrayData(name, bumpers);

    return (
        roomArrayStrings.join("\n\n") +
        doorArrayString +
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
