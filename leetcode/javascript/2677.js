/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
// Link: https://leetcode.com/problems/chunk-array/description/ 
var chunk = function (arr, size) {
    // let ans = [];
    // for (let i = 0; i < arr.length; i += size) {
    //     ans.push(arr.slice(i, i + size));
    // }
    // return ans;

    return arr.reduce((ans, e) => {
        let last = ans[ans.length - 1];
        if (!last || last.length === size) {
            ans.push([e]);
        } else {
            last.push(e);
        }
        return ans;
    }, []);
};
