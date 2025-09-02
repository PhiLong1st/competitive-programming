/*
    Code by: KoKoDuDu
    Created: 2025.04.24 21:35:48
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    int cnt = 0;
    int ans = 0;
    for (auto c : s) {
        cnt += c == '1';
    }
    for (auto c : s) {
        if (c == '0') {
            ans += cnt + 1;
        }
        else {
            ans += cnt - 1;
        }
    }
    cout << ans << '\n';
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