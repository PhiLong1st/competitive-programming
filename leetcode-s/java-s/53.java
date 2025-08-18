/*
 * @lc app=leetcode id=53 lang=java
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        int curMax = 0, maxTillNow = Integer.MIN_VALUE;

        for (int c : nums) {
            curMax = Math.max(c, curMax + c);
            maxTillNow = Math.max(maxTillNow, curMax);
        }

        return maxTillNow;
    }
}
// @lc code=end

