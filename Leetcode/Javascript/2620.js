/**
 * @param {number} n
 * @return {Function} counter
 */
// Link: https://leetcode.com/problems/counter/description/
var createCounter = function (n) {

    return function () {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */