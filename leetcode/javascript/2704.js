/**
 * @param {string} val
 * @return {Object}
 */
// Link: https://leetcode.com/problems/to-be-or-not-to-be/description/
var expect = function (val) {
    return {
        toBe: function (x) {
            if (x === val) {
                return true;
            } else {
                throw Error("Not Equal");
            }
        },
        notToBe: function (x) {
            if (x !== val) {
                return true;
            } else {
                throw Error("Equal");
            }
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */