/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i/
*/
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(51, 0));
        for (int i = 0; i <= nums[0]; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= nums[i]; j++) {
                for (int u = 0; u <= j; u++) {
                    int x = nums[i - 1] - u;
                    int y = nums[i] - j;
                    if (x >= y) {
                        dp[i][j] += dp[i - 1][u];
                        if (dp[i][j] >= MOD) {
                            dp[i][j] -= MOD;
                        }
                    }
                }
            }
        }
        for (int i = 0; i <= 50; i++) {
            ans += dp[n - 1][i];
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        return ans;
    }
};