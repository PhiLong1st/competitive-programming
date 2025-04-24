
/*
    Code by: KoKoDuDu
    Created: 2025.04.24 21:38:47
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < x; ++i) {
        cout << i << ' ';
    }

    for (int i = n - 1; i >= x; --i) {
        cout << i << ' ';
    }

    cout << '\n';
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