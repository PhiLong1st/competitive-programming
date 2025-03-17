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

    vector<int> a(n), b(m);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    sort(a.begin(), a.end());

    int gcd_value = 0;
    for (int i = 1; i < n; ++i) {
        gcd_value = gcd(gcd_value, a[i] - a[0]);
    }

    for (const auto& bi : b) {
        cout << gcd(gcd_value, a[0] + bi) << ' ';
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