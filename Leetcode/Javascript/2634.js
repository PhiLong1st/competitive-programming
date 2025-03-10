/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
// Link: https://leetcode.com/problems/filter-elements-from-array/description/
var filter = function (arr, fn) {
    let filteredArr = [];
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            filteredArr.push(arr[i]);
        }
    }
    return filteredArr;
};