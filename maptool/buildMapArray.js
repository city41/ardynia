const MAP_WIDTH_PX = 128 - 16;
const MAP_HEIGHT_PX = 64;

// need to subtract 1 from each value as tiled is 1 based
function getNibbles(data) {
    const nibbles = [];

    for (var i = 0; i < data.length; i += 2) {
        const upperNibble = ((data[i] - 1) << 4) & 0xf0;
        const lowerNibble = (data[i + 1] - 1) & 0x0f;

        nibbles.push(upperNibble | lowerNibble);
    }

    return nibbles;
}

module.exports = function buildMapArray(name, layer, tileSize) {
    const { data, width, height } = layer;

    const mapWidth = width / (MAP_WIDTH_PX / tileSize);
    const mapHeight = height / (MAP_HEIGHT_PX / tileSize);
    const nibbles = getNibbles(data);

    return `
const uint8_t PROGMEM ${name}_map[${nibbles.length + 3}] = {
    // map width, map height (in rooms), tile size (in pixels)
    ${mapWidth}, ${mapHeight}, ${tileSize},
    ${nibbles.join(", ")}
};`;
};
