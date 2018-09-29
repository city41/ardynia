const crypto = require("crypto");
const ROOM_WIDTH_PX = 128 - 16;
const ROOM_HEIGHT_PX = 64;
const COMPRESSION_TILE = 0xf;

function toNibbles(data) {
    const nibbles = [];

    for (var i = 0; i < data.length; i += 2) {
        const upperNibble = (data[i] << 4) & 0xf0;
        const lowerNibble = data[i + 1] & 0x0f;

        nibbles.push(upperNibble | lowerNibble);
    }

    return nibbles;
}

/**
 * tiled's tile IDs are one based, convert them to
 * be zero based
 */
function subtractOne(data) {
    return data.map(d => d - 1);
}

function compressRoom(roomData) {
    let i = 0;
    let e = 0;
    const compressedData = [];

    while (i < roomData.length) {
        e = 0;
        while (
            i + e < roomData.length &&
            e < 19 &&
            roomData[i] === roomData[i + e]
        ) {
            e += 1;
        }

        if (e > 3) {
            compressedData.push(COMPRESSION_TILE);
            compressedData.push(e - 4);
            compressedData.push(roomData[i]);
        } else {
            for (let ii = i; ii < i + e; ++ii) {
                compressedData.push(roomData[ii]);
            }
        }

        i = i + e;
    }

    if (compressedData.length % 2 === 1) {
        compressedData.push(0);
    }
    // console.log("non compressed room", roomData.join(", "));
    // console.log("compressed room", compressedData.join(", "));
    // console.log("non compressed room", roomData.length);
    // console.log("compressed room", compressedData.length);
    // console.log(
    //     "hash",
    //     crypto
    //         .createHash("sha1")
    //         .update(compressedData.join(""))
    //         .digest("hex")
    // );

    return compressedData;
}

function roomBasedCompression(data, linearRoomSize) {
    const numRooms = data.length / linearRoomSize;

    let compressedRoomsData = [];
    const compressedRoomIndices = [];

    for (let room = 0; room < numRooms; room += 1) {
        const roomData = data.slice(
            room * linearRoomSize,
            (room + 1) * linearRoomSize
        );
        const compressedRoomData = compressRoom(roomData);

        compressedRoomIndices.push(compressedRoomsData.length);
        compressedRoomsData = compressedRoomsData.concat(compressedRoomData);
    }

    return {
        roomIndices: compressedRoomIndices,
        data: compressedRoomsData
    };
}

function encodeRoomIndicesBasedOnNibbles(roomIndices) {
    return roomIndices.reduce((building, roomIndex) => {
        // since the data is ultimately stored in nibbles, need to
        // halve the index to get the real index
        roomIndex = roomIndex / 2;
        const significantByte = roomIndex >> 8;
        const leastSignificantByte = roomIndex & 0xff;

        // the pgm_read_word macro is little endian, so encode to match
        return building.concat(leastSignificantByte, significantByte);
    }, []);
}

/**
 * Tiled gives us data that is map based, this method converts it to be room based
 *
 * Pretend the map size is 2 rooms by 2 rooms, and each room is 3 tiles by 2 tiles,
 * Tiled gives us [0,0,0, 1,1,1, 0,0,0, 1,1,1, 2,2,2, 3,3,3, 2,2,2, 3,3,3]
 *
 * This function converts it to:
 * [0,0,0, 0,0,0, 1,1,1, 1,1,1, 2,2,2, 2,2,2, 3,3,3, 3,3,3]
 */
function convertDataToBeRoomBased(
    mapData,
    mapWidthInRooms,
    mapHeightInRooms,
    roomTileWidth,
    roomTileHeight
) {
    let dataByRoom = [];

    for (let ry = 0; ry < mapHeightInRooms; ++ry) {
        for (let rx = 0; rx < mapWidthInRooms; ++rx) {
            for (let row = 0; row < roomTileHeight; ++row) {
                const mi =
                    (ry * roomTileHeight + row) *
                        mapWidthInRooms *
                        roomTileWidth +
                    rx * roomTileWidth;
                dataByRoom = dataByRoom.concat(
                    mapData.slice(mi, mi + roomTileWidth)
                );
            }
        }
    }

    return dataByRoom;
}

module.exports = function buildMapArray(name, layer, tileSize) {
    const { data, width, height } = layer;

    const roomTileWidth = ROOM_WIDTH_PX / tileSize;
    const roomTileHeight = ROOM_HEIGHT_PX / tileSize;

    const mapWidth = width / roomTileWidth;
    const mapHeight = height / roomTileHeight;

    const linearRoomSize = roomTileWidth * roomTileHeight;

    const dataByRooms = convertDataToBeRoomBased(
        data,
        mapWidth,
        mapHeight,
        roomTileWidth,
        roomTileHeight
    );

    const { roomIndices, data: compressedData } = roomBasedCompression(
        subtractOne(dataByRooms),
        linearRoomSize
    );
    const nibbles = toNibbles(compressedData);
    const roomIndicesEncodedto16Bit = encodeRoomIndicesBasedOnNibbles(
        roomIndices
    );

    const arrayLength = nibbles.length + roomIndicesEncodedto16Bit.length + 4;
    const arrayLengthAs16Bit = encodeRoomIndicesBasedOnNibbles([
        arrayLength * 2
    ]);

    console.log("original data length", data.length);
    console.log("length if only did nibbles", data.length / 2);
    console.log("compressed length", arrayLength - 3);
    console.log(
        "compression ratio",
        1 - ((arrayLength - 3) / (data.length / 2)).toFixed(2)
    );

    return `
const uint8_t PROGMEM ${name}_map[${arrayLength}] = {
    // array length (16 bit, little endian), map width, map height (in rooms)
    ${arrayLengthAs16Bit.join(", ")}, ${mapWidth}, ${mapHeight},
    // room indices (16 bit, little endian), ${
        roomIndicesEncodedto16Bit.length
    } bytes
${renderRoomIndices(roomIndicesEncodedto16Bit)}
    // compressed room data, ${nibbles.length} bytes
    ${nibbles.map(n => "0x" + n.toString(16)).join(", ")}
};`;
};

function renderRoomIndices(indices) {
    let code = "";

    for (let i = 0; i < indices.length; i += 2) {
        code += `    // room ${i / 2}, index ${(indices[i + 1] << 8) |
            indices[i]}\n`;
        code += `    ${indices[i]}, ${indices[i + 1]},\n`;
    }

    return code;
}
