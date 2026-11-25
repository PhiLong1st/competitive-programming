/*
    Code by: KoKoDuDu
    Created: 2025.04.08 21:44:55
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int  cnt = 0;
    int n = s.size();
    for (char c : s) {
        cnt += (c == '0');
    }

    if (cnt == 0) {
        cout << n - 1 << '\n';
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        cnt -= (c == '0');
        if (c != '0')
        {
            cout << n - 1 - cnt << '\n';
            return;
        }
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