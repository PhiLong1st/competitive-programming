/**
 * @return {Function}
 */
// Link: https://leetcode.com/problems/create-hello-world-function/description/
var createHelloWorld = function () {

    return function (...args) {
        return "Hello World";

    }
};


const f = createHelloWorld();
f(); // "Hello World"
