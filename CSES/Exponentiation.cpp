/*
    Code by: KoKoDuDu
    Created: 28.10.2024 20:59:28
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
int mod_exp(int n, int x) {
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
    int x, n;
    cin >> x >> n;
    cout << mod_exp(x, n) << '\n';
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
