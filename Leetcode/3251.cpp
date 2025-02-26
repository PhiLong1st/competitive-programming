/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/find-the-count-of-monotonic-pairs-ii/
*/
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        for (int i = 0; i <= nums[0]; i++) {
            dp[0][i] = 1;
        }
        vector<int> sum(1011, 0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 1000; j++) {
                sum[j] = 0;
            }
            sum[0] = dp[i - 1][0];
            for (int j = 1; j <= 1000; j++) {
                sum[j] = sum[j - 1] + dp[i - 1][j];
                if (sum[j] >= MOD) {
                    sum[j] -= MOD;
                }
            }
            for (int j = 0; j <= nums[i]; j++) {
                int val = min(j, nums[i - 1] - nums[i] + j);
                if (val >= 0)
                    dp[i][j] += sum[val];
                if (dp[i][j] >= MOD) {
                    dp[i][j] -= MOD;
                }
            }
        }
        for (int i = 0; i <= 1000; i++) {
            ans += dp[n - 1][i];
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        return ans;
    }
};