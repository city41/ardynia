module.exports = function getUsedCharacters(inputStrings) {
    const charMap = inputStrings.reduce((buildingMap, str) => {
        str.value.split("").forEach(charStr => {
            buildingMap[charStr] = buildingMap[charStr] || 0;
            buildingMap[charStr] += 1;
        });

        return buildingMap;
    }, {});

    return Object.keys(charMap).sort();
};
