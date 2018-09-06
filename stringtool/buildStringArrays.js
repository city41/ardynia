function getBytesForString(str, encoding) {
    return str.split("").map(c => encoding[c]);
}

module.exports = function buildStringArrays(stringEntries, encoding) {
    const stringBytes = stringEntries.map(s => {
        const actualBytes = getBytesForString(s.value, encoding);

        return `
// "${s.value}"
const uint8_t ${s.key}_string[${actualBytes.length + 1}] PROGMEM = {
    ${actualBytes.join(", ")}, 0xFF
};`;
    });

    return stringBytes.join("\n\n");
};
