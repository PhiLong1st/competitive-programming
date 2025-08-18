/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
// Link: https://leetcode.com/problems/counter-ii/description/?envType=study-plan-v2&envId=30-days-of-javascript
var createCounter = function (init) {
    let tmp = init;
    return {
        increment: function () {
            return ++tmp;
        },
        reset: function () {
            tmp = init;
            return tmp;
        },
        decrement: function () {
            return --tmp;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */