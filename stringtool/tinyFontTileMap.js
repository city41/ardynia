const SPACE = 0;
const COLON = 26;

const ACode = "A".charCodeAt(0);
const ZCode = "Z".charCodeAt(0);

const tinyFontMap = {
    " ": 0,
    ":": 27
};

for (let i = ACode; i < ZCode; ++i) {
    tinyFontMap[String.fromCharCode(i)] = i - ACode + 1;
}

module.exports = tinyFontMap;
