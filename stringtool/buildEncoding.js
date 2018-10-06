module.exports = function buildEncoding(usedCharacters) {
    const spaceUsed = usedCharacters.indexOf(" ") > -1;
    const exclamationUsed = usedCharacters.indexOf("!") > -1;

    usedCharacters = usedCharacters.filter(c => c != " " && c != "!").sort();

    const encoding = {};
    const spaceOffset = spaceUsed ? 1 : 0;

    for (let index = 0; index < usedCharacters.length; ++index) {
        encoding[usedCharacters[index]] = index + spaceOffset;
    }

    if (spaceUsed) {
        encoding[" "] = 0;
    }

    if (exclamationUsed) {
        encoding["!"] = usedCharacters.length + 1;
    }

    console.log(
        "total number of characters in encoding",
        Object.keys(encoding).length
    );
    console.log(Object.keys(encoding).join(", "));

    return encoding;
};
