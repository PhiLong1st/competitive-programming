/*
    Code by: KoKoDuDu
    Created: 2025.03.22 20:20:52
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, r, c;
    string s;
    cin >> n >> r >> c;
    cin >> s;

    vector<pll> a(n + 1);
    map<pll, int> cnt;

    a[0] = { 0, 0 };
    cnt[a[0]] = 1;

    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1];

        if (s[i - 1] == 'N') a[i].first--;
        if (s[i - 1] == 'S') a[i].first++;
        if (s[i - 1] == 'W') a[i].second--;
        if (s[i - 1] == 'E') a[i].second++;

        pll delta = { a[i].first - r,   a[i].second - c };
        cnt[a[i]] = 1;
        cout << cnt[delta];
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
