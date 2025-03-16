/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
// Link: https://leetcode.com/problems/flatten-deeply-nested-array/description/ 
var flat = function (arr, n) {
    if (n == 0) {
        return arr;
    }

    let ans = [];

    for (let item of arr) {
        if (Array.isArray(item)) {
            let tmp = flat(item, n - 1);
            for (let x of tmp) {
                ans.push(x);
            }
        } else {
            ans.push(item);
        }
    }

    return ans;
};