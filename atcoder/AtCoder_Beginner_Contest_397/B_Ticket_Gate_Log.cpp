/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    s = " " + s;
    int cnt = 0;
    for (int i = 1; i < s.size(); ++i) {
        int pos = cnt + i;
        if (pos % 2) {
            if (s[i] != 'i') {
                cnt++;
            }
        }
        else {
            if (s[i] != 'o') {
                cnt++;
            }
        }
    }

    if ((cnt + s.size()) % 2 == 0) {
        cnt++;
    }

    cout << cnt;
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