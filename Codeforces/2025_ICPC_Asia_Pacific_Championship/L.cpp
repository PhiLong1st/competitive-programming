/*
    Code by: KoKoDuDu

*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int r, c, n, p;
    cin >> r >> c >> n >> p;
    vector<vector<int>>a(r + 2, vector<int>(c + 2));
    vector<pll>save(n + 1);
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> a[i][j];
            if (a[i][j] != 0)
                save[a[i][j]] = { i, j };
        }
    }
    set<pll> st;
    int ans = 0;
    for (int i = 0; i < p; ++i) {
        int x = save[p].first, y = save[p].second;
        if (a[x - 1][y] != 0 && a[x - 1][y] + i <= n) {
            st.insert({ p, a[x - 1][y] + i });
        }
        if (a[x + 1][y] != 0 && a[x + 1][y] + i <= n) {
            st.insert({ p, a[x + 1][y] + i });
        }
        if (a[x][y - 1] != 0 && a[x][y - 1] + i <= n) {
            st.insert({ p, a[x][y - 1] + i });
        }
        if (a[x][y + 1] != 0 && a[x][y + 1] + i <= n) {
            st.insert({ p, a[x][y + 1] + i });
        }
        // for (auto x : st) {
        //     cout << x.first << ' ' << x.second << '\n';
        // }
        // cout << x << ' ' << y << '\n';
        // cout << "---\n";
        // for (int j = 1; j <= n; ++j) {
        //     if (abs(save[p].first - save[j].first) + abs(save[p].second - save[j].second) == 1) {
        //         st.insert({ p,j });
        //         // cerr << p << ' ' << j << '\n';
        //     }
        // }
        // for (int j = n; j >= 1; --j) {
        //     save[j] = save[j - 1];
        // }
        // cout << i << '\n';
        // for (int j = 1; j <= n; ++j) {
        //     cout << save[j].first << ' ' << save[j].second << '\n';
        // }
        save[p] = save[p - i - 1];
    }
    // for (auto x : st) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    cout << st.size() << "/" << n - 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}