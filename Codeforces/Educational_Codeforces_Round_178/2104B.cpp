
/*
    Code by: KoKoDuDu
    Created: 2025.04.28 21:43:01
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pf(n + 1), maxL(n + 1), minR(n + 2, INT_MAX);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
        maxL[i] = max(maxL[i - 1], a[i]);
    }

    for (int i = n; i >= 1; --i) {
        minR[i] = min(minR[i + 1], a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        int sum = pf[n] - pf[n - i];
        int maxx = maxL[n - i];
        // cerr << sum << ' ' << a[n - i + 1] << ' ' << maxx << '\n';
        if (a[n - i + 1] < maxx) {
            cout << sum - a[n - i + 1] + maxx << ' ';
        }
        else {
            cout << sum << ' ';
        }
    }
    cout << '\n';
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