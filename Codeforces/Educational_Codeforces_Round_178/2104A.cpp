
/*
    Code by: KoKoDuDu
    Created: 2025.04.28 21:36:00
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int dis = b - a;
    c -= dis;
    if (c >= b && (c - b) % 3 == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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