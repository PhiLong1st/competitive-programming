/*
    Code by: KoKoDuDu

*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> dist(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = abs(pos[i] - pos[j]);
        }
    }
    for (int i = 1; i < n; ++i) {
        dp[i][i + 1] = dist[i][i + 1];
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            // dp[j - i + 1][j] = dp[j - i + 2][j] + dist[j - i + 1][j - i + 2];
            for (int u = j - i + 2; u <= j; ++u) {
                dp[j - i + 1][j] = min(dp[j - i + 1][j], dp[j - i + 1][u] + dp[u][j]);
                dp[j - i + 1][j] = min(dp[j - i + 1][j], dp[j - i + 1][u] + dist[u][j]);
                if (j - i + 1 == 4 && j == 6) {
                    cerr << u << ' ';
                    cerr << min(dist[j - i + 1][j], dist[j - i + 1][u]) << '\n';
                }
            }
            cout << j - i + 1 << ' ' << j << ' ' << dp[j - i + 1][j] << '\n';
        }
    }
    cout << dp[1][n];
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