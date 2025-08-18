/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/manhattan-distances-of-all-arrangements-of-pieces/
*/
class Solution {
public:
    struct Combinatorics {
        long long n, MOD;
        vector<long long> fact, inv, fact_inv;
        Combinatorics(long long n, long long MOD)
            : n(n), MOD(MOD), fact(n + 1), inv(n + 1), fact_inv(n + 1) {
            inv[1] = 1;
            for (long long i = 2; i <= n; ++i) {
                inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
            }
            fact[0] = fact_inv[0] = 1;
            for (long long i = 1; i <= n; ++i) {
                fact[i] = fact[i - 1] * i % MOD;
                fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
            }
        }
        long long get_nCk(long long n, long long k) {
            if (n < 0 || k < 0 || n < k)
                return 0;
            return fact[n] * fact_inv[k] % MOD * fact_inv[n - k] % MOD;
        }
        long long get_inv_fact(long long i) { return fact_inv[i]; }
        long long get_fact(long long i) { return fact[i]; }
        long long get_inv(long long i) { return inv[i]; }
    };
    int distanceSum(int m, int n, int k) {
        long long ans = 0;
        long long MOD = 1e9 + 7;
        Combinatorics comb(100001, MOD);
        long long sum = 0;
        for (long long i = 1; i <= m; ++i) {
            sum += 1LL * (i * i - i * (i + 1) / 2)  * 1LL * n * n;
            sum %= MOD;
        }
        for (long long i = 1; i <= n; ++i) {
            sum += 1LL * (i * i - i * (i + 1) / 2) * 1LL * m * m;
            sum %= MOD;
        }
        return sum * comb.get_nCk(m * n - 2, k - 2) % MOD;
    }
};