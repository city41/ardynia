// generates an image to drop into tiled so that the dungeons are color coded

const Canvas = require("canvas");
const fs = require("fs");

// const DATA = [
//     [0, 2, 3, 3, 3, 3, 3, 3, 3, 0],
//     [1, 2, 2, 2, 2, 2, 3, 3, 3, 3],
//     [1, 1, 1, 1, 1, 2, 3, 2, 3, 3],
//     [1, 1, 2, 2, 1, 2, 2, 2, 3, 0],
//     [0, 1, 1, 2, 2, 2, 3, 3, 3, 0],
//     [1, 1, 1, 1, 2, 2, 2, 3, 3, 3]
// ];

const DATA = [
    [3, 3, 3, 3, 3, 3, 3, 3],
    [3, 1, 1, 3, 3, 3, 2, 2],
    [3, 3, 1, 3, 0, 3, 3, 2],
    [1, 1, 1, 1, 3, 3, 2, 2],
    [1, 0, 1, 1, 3, 2, 2, 0],
    [1, 1, 3, 3, 3, 3, 2, 0],
    [1, 1, 1, 1, 3, 2, 2, 0],
    [1, 1, 2, 2, 2, 2, 2, 2]
];

const TILE_SIZE = 16;
const WIDTH_IN_ROOMS = DATA[0].length;
const HEIGHT_IN_ROOMS = DATA.length;
const TILES_PER_ROW = 7;
const TILES_PER_COLUMN = 4;
const ROOM_WIDTH_PX = TILES_PER_ROW * TILE_SIZE;
const ROOM_HEIGHT_PX = TILES_PER_COLUMN * TILE_SIZE;
const IMAGE_WIDTH_PX = WIDTH_IN_ROOMS * ROOM_WIDTH_PX;
const IMAGE_HEIGHT_PX = HEIGHT_IN_ROOMS * ROOM_HEIGHT_PX;

const COLORS = [
    "rgba(0,0,0,0.3)",
    "rgba(255,0,0,0.3)",
    "rgba(255,255,0,0.3)",
    "rgba(0,255,0,0.3)",
    "rgba(0,0,255,0.3)",
    "rgba(0,255,255,0.3)"
];

const canvas = new Canvas(IMAGE_WIDTH_PX, IMAGE_HEIGHT_PX);
const ctx = canvas.getContext("2d");

ctx.fillStyle = "rgba(0,0,0,0)";
ctx.fillRect(0, 0, IMAGE_WIDTH_PX, IMAGE_HEIGHT_PX);

for (let y = 0; y < DATA.length; ++y) {
    for (let x = 0; x < DATA[y].length; ++x) {
        const colorIndex = DATA[y][x];
        const color = COLORS[colorIndex];
        console.log("color", color);
        ctx.fillStyle = color;
        ctx.fillRect(
            x * ROOM_WIDTH_PX,
            y * ROOM_HEIGHT_PX,
            ROOM_WIDTH_PX,
            ROOM_HEIGHT_PX
        );
    }
}

const buf = canvas.toBuffer();
fs.writeFileSync("dungeonOverlay.png", buf);
