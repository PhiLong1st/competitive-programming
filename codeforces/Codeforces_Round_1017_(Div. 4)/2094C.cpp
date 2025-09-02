
/*
    Code by: KoKoDuDu
    Created: 2025.04.14 00:04:54
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> p(2 * n + 1);
    vector<bool> used(2 * n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            p[i + j] = a[i][j];
            used[a[i][j]] = true;
        }
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (!used[i]) {
            p[1] = i;
        }
    }
    for (int i = 1; i <= 2 * n; ++i) {
        cout << p[i] << " ";
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