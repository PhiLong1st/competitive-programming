
/*
    Code by: KoKoDuDu
    Created: 2025.04.13 22:57:39
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int gap = abs(l);
    if (abs(l) > m) {
        cout << -m << ' ' << 0 << '\n';
    }
    else {
        cout << l << ' ' << l + m << '\n';
    }
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