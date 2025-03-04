/*
    Code by: KoKoDuDu

*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    int gcd = 0;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        gcd = __gcd(a[i], gcd);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        cout << __gcd(gcd, b[i]) << ' ';
    }
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