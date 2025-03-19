/*
    Code by: KoKoDuDu

*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;


pll cal(int s, int v) {
    pll ans = { -1LL, -1LL };

    int delta = s * s - 4 * v;

    if (delta < 0) {
        return ans;
    }

    int sq = sqrt(delta);

    if (sq * sq != delta) {
        return ans;
    }

    int x1 = s + sq;
    int x2 = s - sq;

    if (x1 > 0 && x1 % 2 == 0) {
        ans.first = x1 / 2;
        ans.second = x1 / 2 - s;
    }

    if (x2 > 0 && x2 % 2 == 0) {
        ans.first = x2 / 2;
        ans.second = x2 / 2 - s;
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i * i * i <= n; ++i) {
        int val = n - i * i * i;
        if (val == 0 || val % (3 * i) != 0) continue;

        val /= 3 * i;

        int s = i, v = val;

        pll ans = cal(s, -v);

        // cout << s << ' ' << v << ' ' << ans.first << ' ' << ans.second << '\n';

        if (ans != make_pair(-1LL, -1LL)) {
            cout << ans.first << ' ' << ans.second;
            return;
        }
    }

    cout << -1;
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