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
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> cal(n + 1, vector<int>(n + 1)), dp(n + 1, vector<int>(2));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        cal[i][i] = a[i] * b[i];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            cal[j - i + 1][j] = cal[j - i + 2][j - 1] + a[j - i + 1] * b[j] + a[j] * b[j - i + 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + a[i] * b[i];
        dp[i][1] = dp[i - 1][1] + a[i] * b[i];
        for (int j = 1; j <= i; ++j) {
            dp[i][1] = max(dp[i][1], dp[j - 1][0] + cal[j][i]);
        }
        ans = max({ ans, dp[i][0], dp[i][1] });
    }
    cout << ans << '\n';
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