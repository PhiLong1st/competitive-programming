/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
// Link: https://leetcode.com/problems/return-length-of-arguments-passed/
var argumentsLength = function (...args) {
    return args.length;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */