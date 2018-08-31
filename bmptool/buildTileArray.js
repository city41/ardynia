const fs = require("fs");
const Canvas = require("canvas");
const Image = Canvas.Image;

function isBlack(pixelColor) {
    return (
        pixelColor[0] === 0 &&
        pixelColor[1] === 0 &&
        pixelColor[2] === 0 &&
        pixelColor[3] === 255
    );
}

function isWhite(pixelColor) {
    return (
        pixelColor[0] === 255 &&
        pixelColor[1] === 255 &&
        pixelColor[2] === 255 &&
        pixelColor[3] === 255
    );
}

function isBlackOrWhite(pixelColor) {
    return isBlack(pixelColor) || isWhite(pixelColor);
}

function explainNamingAndExit(name) {
    console.error(
        "pngs must be named in format: <name>_<width>x<height>.png, ie foo_6x8.png"
    );
    console.error("name given:", name);
    process.exit(1);
}

function getTileSizeFromFileName(name) {
    const underscoreSplit = name.split("_");
    if (underscoreSplit.length !== 2) {
        explainNamingAndExit(name);
    }
    const xSplit = underscoreSplit[1].split("x");

    if (xSplit.length !== 2) {
        explainNamingAndExit(name);
    }

    const origWidth = parseInt(xSplit[0]);
    const origHeight = parseInt(xSplit[1]);

    if (
        isNaN(origWidth) ||
        isNaN(origHeight) ||
        origWidth < 0 ||
        origHeight < 0
    ) {
        explainNamingAndExit(name);
    }

    return { origWidth, origHeight };
}

/**
 * Given a tile image file path, returns a string that is C++ code
 * of the tile data, ready to be consumed by arduboy programs
 *
 * This code was taken from Team A.R.G.'s arduboy-tile-converter:
 * https://teamarg.github.io/arduboy-tile-converter/
 */
module.exports = function buildTileArray(name, tileFile) {
    const { origWidth, origHeight } = getTileSizeFromFileName(name);

    const fileData = fs.readFileSync(tileFile);
    const img = new Image();
    img.src = fileData;

    const imgNW = img.width;
    const imgNH = img.height;

    const canvas = new Canvas(img.width, img.height);
    const ctx = canvas.getContext("2d");
    ctx.drawImage(img, 0, 0, imgNW, imgNH);

    let pageCount = Math.ceil(imgNH / 8);
    let columnCount = imgNW;
    let currentByte = 0;
    let frameCounter = 0;

    let spriteByteFrames = [];
    let maskByteFrames = [];
    spriteByteFrames[frameCounter] = [];
    maskByteFrames[frameCounter] = [];

    let currentSpriteBytesFrame = spriteByteFrames[frameCounter];
    let currentMaskBytesFrame = maskByteFrames[frameCounter];

    let bytesPerFrame = (origWidth * origHeight) / 8;

    // Read the sprite page-by-page
    for (let page = 0; page < pageCount; page++) {
        // Read the page column-by-column
        for (let column = 0; column < columnCount; column++) {
            // Read the column into a byte
            let spriteByte = 0;
            let maskByte = 0;
            for (let yPixel = 0; yPixel < 8; yPixel++) {
                // If the color of the pixel is not black, count it as white
                let pixelColor = ctx.getImageData(
                    column,
                    page * 8 + yPixel,
                    1,
                    1
                ).data;
                if (isWhite(pixelColor)) {
                    spriteByte |= 1 << yPixel;
                }
                if (isBlackOrWhite(pixelColor)) {
                    maskByte |= 1 << yPixel;
                }
            }

            // jam the bytes into the building arrays
            let digitSpriteStr = spriteByte.toString(16);
            let digitMaskStr = maskByte.toString(16);

            if (digitSpriteStr.length == 1) {
                digitSpriteStr = "0" + digitSpriteStr;
            }
            if (digitMaskStr.length == 1) {
                digitMaskStr = "0" + digitMaskStr;
            }

            currentSpriteBytesFrame.push("0x" + digitSpriteStr);
            currentMaskBytesFrame.push("0x" + digitMaskStr);

            if (
                currentByte % bytesPerFrame === bytesPerFrame - 1 &&
                frameCounter < imgNH / origHeight - 1
            ) {
                frameCounter++;

                spriteByteFrames[frameCounter] = [];
                maskByteFrames[frameCounter] = [];

                currentSpriteBytesFrame = spriteByteFrames[frameCounter];
                currentMaskBytesFrame = maskByteFrames[frameCounter];

                currentByte = 0;
            } else {
                currentByte++;
            }
        }
    }

    // Generate the sprite string
    const spriteStringSeed =
        "const uint8_t PROGMEM " +
        name.split("_")[0] +
        "_tiles[] = {" +
        "\n    // width, height,\n    " +
        origWidth +
        ", " +
        origHeight +
        ",";

    const maskStringSeed =
        "const uint8_t PROGMEM " + name.split("_")[0] + "_mask[] = {";

    const comboStringSeed =
        "const uint8_t PROGMEM " +
        name.split("_")[0] +
        "_plus_mask[] = {" +
        "\n    // width, height,\n    " +
        origWidth +
        ", " +
        origHeight +
        ",";

    const spriteString =
        spriteByteFrames.reduce((building, frame, i) => {
            return (
                building +
                "\n    // frame " +
                i +
                "\n    " +
                frame.join(",") +
                ","
            );
        }, spriteStringSeed) + "\n};";

    const maskString =
        maskByteFrames.reduce((building, frame, i) => {
            return (
                building +
                "\n    // frame " +
                i +
                "\n    " +
                frame.join(",") +
                ","
            );
        }, maskStringSeed) + "\n};";

    const combinedFrames = spriteByteFrames.reduce(
        (building, spriteFrame, i) => {
            building.push(spriteFrame);
            building.push(maskByteFrames[i]);
            return building;
        },
        []
    );

    const comboString =
        combinedFrames.reduce((building, frame, i) => {
            const commentLabel =
                i % 2 == 0
                    ? `frame ${Math.floor(i / 2)}`
                    : `mask ${Math.floor(i / 2)}`;

            return (
                building +
                `\n    // ${commentLabel} ` +
                "\n    " +
                frame.join(",") +
                ","
            );
        }, comboStringSeed) + "\n};";

    return {
        spriteString,
        maskString,
        comboString
    };
};
