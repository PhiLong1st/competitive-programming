
/*
    Code by: KoKoDuDu
    Created: 28.10.2024 21:27:45
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

int mod_exp(int n, int x, int MOD) {
    int res = 1;
    while (x > 0) {
        if (x & 1) {
            res = (res * n) % MOD;
        }
        n = (n * n) % MOD;
        x >>= 1;
    }
    return res;
}

void solve() {
    int x, a, b;
    cin >> x >> a >> b;
    cout << mod_exp(x, mod_exp(a, b, MOD - 1), MOD) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}