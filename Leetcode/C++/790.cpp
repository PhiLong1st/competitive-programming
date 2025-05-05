
/*
    Code by: KoKoDuDu
    Created: 2025.05.05 17:15:09
*/
class Solution {
public:
    int numTilings(int n) {
        if (n <= 2) {
            return n;
        }
        int ans = 0;
        int MOD = 1e9 + 7;
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (1LL * 2 * dp[i - 1] + 1LL * dp[i - 3]) % MOD;
            dp[i] %= MOD;
        }
        return dp[n];
    }
};