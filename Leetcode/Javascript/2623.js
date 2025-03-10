/**
 * @param {Function} fn
 * @return {Function}
 */
//  Link: https://leetcode.com/problems/memoize/description/
function memoize(fn) {
    let cache = {};
    return function (...args) {
        let key = JSON.stringify(args);
        if (!(key in cache)) {
            cache[key] = fn(...args);
        }
        return cache[key];
    }
}

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */