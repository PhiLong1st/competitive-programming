/**
 * @param {Function} fn
 * @return {Object}
 */
// Link: https://leetcode.com/problems/group-by/description/
Array.prototype.groupBy = function (fn) {

    return this.reduce((arr, x) => {
        let id = fn(x);

        if (!arr[id]) {
            arr[id] = [];
        }

        arr[id].push(x);

        return arr;
    }, {});
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */