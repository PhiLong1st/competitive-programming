
/*
    Code by: KoKoDuDu
    Created: 27.11.2024 13:41:59
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

struct Combinatorics {
    int n, MOD;
    vector<int> fact, inv, fact_inv;

    Combinatorics(int n, int MOD) : n(n), MOD(MOD), fact(n + 1), inv(n + 1), fact_inv(n + 1) {
        inv[1] = 1;
        for (int i = 2; i <= n; ++i) {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
        }

        fact[0] = fact_inv[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
            fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
        }
    }

    int get_nCk(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return fact[n] * fact_inv[k] % MOD * fact_inv[n - k] % MOD;
    }
    int get_inv_fact(int i) {
        return fact_inv[i];
    }
    int get_fact(int i) {
        return fact[i];
    }
    int get_inv(int i) {
        return inv[i];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    Combinatorics comb(1000000, MOD);
    for (int i = 1; i <= n; ++i) {
        ans += comb.get_nCk(n, i) * comb.get_nCk(m - 1, i - 1) % MOD;
        ans %= MOD;
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}