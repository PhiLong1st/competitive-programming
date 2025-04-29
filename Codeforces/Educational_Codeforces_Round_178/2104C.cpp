/*
    Code by: KoKoDuDu
    Created: 2025.04.28 21:54:48
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    if (s[1] == s[n]) {
        cout << ((s[1] == 'A') ? "Alice" : "Bob") << "\n";
        return;
    }

    if (s[1] == 'A') {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            cnt += s[i] == 'B';
        }

        if (cnt == 1) {
            cout << "Alice\n";
            return;
        }
        else {
            cout << "Bob\n";
        }
    }
    else {
        int maxA = 0, maxB = 0;
        for (int i = 2; i < n; ++i) {
            if (s[i] == 'A') {
                maxA = max(maxA, i);
            }
            else {
                maxB = max(maxB, i);
            }
        }
        if (maxA > maxB) {
            cout << "Alice\n";
        }
        else {
            cout << "Bob\n";
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