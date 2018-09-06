const path = require("path");
const fs = require("fs");
const program = require("commander");
const packageJson = require("./package.json");
const getUsedCharacters = require("./getUsedCharacters");
const buildEncoding = require("./buildEncoding");
const buildFontArray = require("./buildFontArray");
const buildStringArrays = require("./buildStringArrays");

program
    .version(packageJson.version)
    .option(
        "-s, --src <json input file>",
        "A JSON file containing the strings to process"
    )
    .option("-o, --dest <dest file>", "The dest file to write the results to")
    .parse(process.argv);

const jsonPath = path.join(process.cwd(), program.src);
const jsonInput = require(jsonPath);
const destPath = program.dest && path.join(process.cwd(), program.dest);
const destBaseName = program.dest ? path.basename(destPath, ".h") : "fontdiet";

const usedCharacters = getUsedCharacters(jsonInput.strings);
const customEncoding = buildEncoding(usedCharacters);

const fontArray = buildFontArray(customEncoding);
const stringArrays = buildStringArrays(jsonInput.strings, customEncoding);

const cppSource = `#ifndef ${destBaseName}_h
#define ${destBaseName}_h

${fontArray}

${stringArrays}

#endif
`;

if (program.dest) {
    fs.writeFileSync(destPath, cppSource);
    console.log("results written to", destPath);
} else {
    console.log(cppSource);
}
