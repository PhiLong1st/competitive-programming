/*
 * @lc app=leetcode id=50 lang=java
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
    public double myPow(double x, int n) {
        double pow = 1;

        if (n < 0) {
            n = -n;
            x = 1 / x;
        }

        while (n != 0) {
            if ((n & 1) != 0) {
                pow *= x;
            }

            x *= x;
            n >>>= 1;
        }

        return pow;
    }
}
// @lc code=end

