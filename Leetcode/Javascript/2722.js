/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
// Link: https://leetcode.com/problems/join-two-arrays-by-id/description/ 
// var join = function (arr1, arr2) {
//     const map = new Map();

//     for (let item of arr1) {
//         map.set(item.id, item);
//     }

//     for (let item of arr2) {
//         if (map.has(item.id)) {
//             Object.assign(map.get(item.id), item);
//         } else {
//             map.set(item.id, item);
//         }
//     }

//     return Array.from(map.values()).sort((a, b) => a.id - b.id);
// };

var join = function (arr1, arr2) {
    const ans = {};

    for (let i = 0; i < arr1.length; i++) {
        ans[arr1[i].id] = arr1[i];
    }

    for (let i = 0; i < arr2.length; i++) {
        if (ans[arr2[i].id]) {
            for (const key in arr2[i]) {
                ans[arr2[i].id][key] = arr2[i][key];
            }
        } else {
            ans[arr2[i].id] = arr2[i];
        }
    }

    return Object.values(ans);
};
