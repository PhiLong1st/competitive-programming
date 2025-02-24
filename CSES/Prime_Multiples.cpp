
/*
    Code by: KoKoDuDu
    Created: 27.11.2024 01:23:14
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int mask = 1; mask < (1 << k); ++mask) {
        int cnt = 0, res = n, tmp = 0;
        for (int i = 0; i < k; ++i) {
            if ((mask & (1 << i))) {
                tmp += res / a[i + 1];
                res /= a[i + 1];
                cnt++;
            }
        }
        if (cnt % 2 == 0) {
            ans -= res;
        }
        else {
            ans += res;
        }
    }
    cout << ans;
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