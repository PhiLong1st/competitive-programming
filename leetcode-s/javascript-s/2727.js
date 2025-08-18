/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
// Link: https://leetcode.com/problems/is-object-empty/description/ 
var isEmpty = function (obj) {
    // for (let _ in obj) {
    //     return false;
    // }
    // return true;
    // return Object.keys(obj).length === 0;
    // console.log(JSON.stringify(obj));
    if (JSON.stringify(obj).length <= 2) return true
    else return false
};