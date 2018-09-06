module.exports = function buildEncoding(usedCharacters) {
    const spaceUsed = usedCharacters.indexOf(" ") > -1;
    const colonUsed = usedCharacters.indexOf(":") > -1;

    usedCharacters = usedCharacters.filter(c => c != " " && c != ":").sort();

    const encoding = {};
    const spaceOffset = spaceUsed ? 1 : 0;

    for (let index = 0; index < usedCharacters.length; ++index) {
        encoding[usedCharacters[index]] = index + spaceOffset;
    }

    if (spaceUsed) {
        encoding[" "] = 0;
    }

    if (colonUsed) {
        encoding[":"] = usedCharacters.length + 1;
    }

    return encoding;
};
