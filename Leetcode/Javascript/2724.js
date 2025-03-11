/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
// Link: https://leetcode.com/problems/sort-by/
var sortBy = function (arr, fn) {
    function cmp(a, b) {
        return (fn(a) < fn(b)) ? -1 : 1;
    }
    return arr.sort(cmp);
};