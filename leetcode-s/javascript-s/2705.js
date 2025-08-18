/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
// Link: https://leetcode.com/problems/compact-object/description/
var compactObject = function (obj) {
    const compacted = {};

    if (obj === null) {
        return null;
    }

    if (Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject);
    }

    if (typeof obj !== "object") {
        return obj;
    }

    for (const key in obj) {
        let value = compactObject(obj[key]);

        if (value) {
            compacted[key] = value;
        }
    }

    return compacted;
};