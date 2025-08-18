
/*
    Code by: KoKoDuDu
    Created: 2025.05.09 19:42:54
*/
class Solution {
public:
    static const int mod = 1e9 + 7;
    using ll = long long;
    vector<ll> fact, inv, invFact;
    void precomp(int n) {
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % mod;

        inv.assign(n + 1, 1);
        for (int i = 2; i <= n; i++)
            inv[i] = mod - (mod / i) * inv[mod % i] % mod;

        invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            invFact[i] = invFact[i - 1] * inv[i] % mod;
    }

    int countBalancedPermutations(string num) {
        int sum = 0, ans = 0;
        int n = num.size();
        int m = n / 2;
        vector<int> cnt(10);
        precomp(n);

        for (auto c : num) {
            sum += c - '0';
        }

        if (sum % 2 != 0) {
            return 0;
        }

        vector<vector<int>> dp(m + 1, vector<int>(sum / 2 + 1));

        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            int d = num[i] - '0';
            cnt[d]++;
            for (int s = sum / 2; s >= d; --s) {
                for (int j = m; j >= 1; --j) {
                    dp[j][s] = (dp[j][s] + dp[j - 1][s - d]) % mod;
                }
            }
        }

        ll res = dp[m][sum / 2];
        res = res * fact[m] % mod * fact[n - m] % mod;
        for (int i : cnt)
            res = res * invFact[i] % mod;
        return res;
    }
};