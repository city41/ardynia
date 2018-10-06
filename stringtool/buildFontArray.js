const fs = require("fs");
const path = require("path");
const Canvas = require("canvas");
const Image = Canvas.Image;
const tinyFontMap = require("./tinyFontTileMap");

const fontPng = path.join(__dirname, "tinyfont_spaceA_Zexclamation.png");
const fileData = fs.readFileSync(fontPng);
const img = new Image();
img.src = fileData;

const masterFontCanvas = new Canvas(img.width, img.height);
const masterCtx = masterFontCanvas.getContext("2d");
masterCtx.drawImage(img, 0, 0, img.width, img.height);

function getTwoCharCanvas(indexA, indexB) {
    const canvas = new Canvas(4, 8);
    const ctx = canvas.getContext("2d");

    // stick first character into top of canvas
    ctx.drawImage(masterFontCanvas, 0, indexA * 4, 4, 4, 0, 0, 4, 4);
    // and second character into bottom of canvas
    ctx.drawImage(masterFontCanvas, 0, indexB * 4, 4, 4, 0, 4, 4, 4);

    return canvas;
}

function isWhite(pixel) {
    return (
        pixel[0] === 255 &&
        pixel[1] === 255 &&
        pixel[2] === 255 &&
        pixel[3] === 255
    );
}

function getArduBytesFromCanvas(canvas) {
    const ctx = canvas.getContext("2d");

    const bytes = [];

    for (let x = 0; x < canvas.width; ++x) {
        let columnByte = 0;
        for (let y = 0; y < canvas.height; ++y) {
            const pixel = ctx.getImageData(x, y, 1, 1).data;

            if (isWhite(pixel)) {
                columnByte |= 1 << y;
            }
        }
        bytes.push("0x" + columnByte.toString(16));
    }

    return bytes;
}

const upperMaskArray = `const uint8_t PROGMEM font_tiles_upper_mask[] = {
    0x0f, 0x0f, 0x0f, 0x0f
};`;

const lowerMaskArray = `const uint8_t PROGMEM font_tiles_lower_mask[] = {
    0xf0, 0xf0, 0xf0, 0xf0
};`;

module.exports = function(encoding) {
    const entries = Object.entries(encoding).sort((a, b) => a[1] - b[1]);

    const byteStrings = [];

    for (let i = 0; i < entries.length - 1; i += 2) {
        const twoCharCanvas = getTwoCharCanvas(
            tinyFontMap[entries[i][0]],
            tinyFontMap[entries[i + 1][0]]
        );

        const bytes = getArduBytesFromCanvas(twoCharCanvas);
        const comment = `    // '${entries[i][0]}' and '${entries[i + 1][0]}'`;
        const bytesAsHexStrings = bytes.map(b => b.toString(16));
        byteStrings.push(
            comment + "\n    " + bytesAsHexStrings.join(",") + ","
        );
    }

    return `const uint8_t PROGMEM font_tiles[] =  {
    // width, height
    4, 8,
${byteStrings.join("\n")}
};

${upperMaskArray}

${lowerMaskArray}`;
};
