#!/usr/bin/env node
const fs = require("fs");
const path = require("path");
const program = require("commander");
const buildTileArray = require("./buildTileArray");
const packageJson = require("./package.json");

program
    .version(packageJson.version)
    .option("-s, --src <src dir of images>", "directory to find the images in")
    .option("-o, --dest <dest file>", "destination file to write the data to")
    .option(
        "-t, --type <bitmap|separate|combined>",
        "what to generate, just the bitmap, bitmap + mask arrays, or combined array"
    )
    .parse(process.argv);

function isInvalidType(type) {
    return ["bitmap", "separate", "combined"].indexOf(type) < 0;
}

if (!program.src || isInvalidType(program.type)) {
    console.error(
        "usage: ardusprites --type <bitmap|separate|combined> --src <src dir of images> --dest <dest file>"
    );
    process.exit(1);
}

function getDesiredArrays(type, allDataArrays) {
    return allDataArrays.reduce((building, entry) => {
        switch (type) {
            case "bitmap":
                building.push(entry.spriteString);
                break;
            case "separate":
                building.push(entry.spriteString);
                building.push(entry.maskString);
                break;
            case "combined":
                building.push(entry.comboString);
                break;
        }

        return building;
    }, []);
}

const files = fs.readdirSync(program.src);

function isPng(file) {
    return path.extname(file) === ".png";
}

const allDataArrays = files.reduce((buildingData, file) => {
    if (isPng(file)) {
        const fullPath = path.join(program.src, file);
        const dataArray = buildTileArray(path.basename(file, ".png"), fullPath);

        return buildingData.concat(dataArray);
    } else {
        console.warn("skipping since it is not a png", file);
        return buildingData;
    }
}, []);

const finalDataArrays = getDesiredArrays(program.type, allDataArrays);

const fileNameRoot = program.dest
    ? path.basename(program.dest, ".h")
    : "ardusprites";

const ifndef = `#ifndef ${fileNameRoot}_h\n#define ${fileNameRoot}_h`;
const endif = "#endif";

const finalFile =
    ifndef + "\n\n" + finalDataArrays.join("\n\n") + "\n\n" + endif;

if (program.dest) {
    fs.writeFileSync(program.dest, finalFile);

    console.log("result written to", program.dest);
} else {
    console.log("no dest file given, writing to stdout");
    console.log(finalFile);
}
