
/*
    Code by: KoKoDuDu
    Created: 30.09.2024 11:23:28
    Link: https://oj.vnoi.info/problem/olp_kc23_beastr
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<vector<int>> prefix_sum(26, vector<int>(n + 1));
    for (int i = 0; i < 26; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix_sum[i][j] = prefix_sum[i][j - 1] + (i + 'a' == s[j - 1]);
        }
    }
    while (q--) {
        int l, r, cnt_odd = 0;
        cin >> l >> r;
        l++;
        r++;
        for (int i = 0; i < 26; ++i) {
            cnt_odd += (prefix_sum[i][r] - prefix_sum[i][l - 1]) % 2;
        }
        cout << cnt_odd / 2 << '\n';
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