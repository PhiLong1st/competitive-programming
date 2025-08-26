/*
    Code by: KoKoDuDu
    Created: 2025.03.21 16:31:40
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int odd = -INT_MAX, even = 0;

    for (int i = 1; i <= n; ++i) {
        if (i % 2) {
            dp[i] = a[i];
            dp[i] = max({ dp[i], odd, even + a[i] });
            odd = max(odd, dp[i]);
        }
        else {
            dp[i] = max({ dp[i], even, odd + a[i] });
            even = max(even, dp[i]);
        }
    }
    cout << dp[n];
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