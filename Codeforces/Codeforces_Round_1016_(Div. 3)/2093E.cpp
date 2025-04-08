/*
    Code by: KoKoDuDu
    Created: 2025.04.08 23:10:52
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int l = 0, r = n + 1, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // mid = 3;
        // cout << mid << "\n";
        map<int, int> save;
        int cnt = 1, cur = 0;

        for (int i = 1; i <= n; ++i) {
            if (save[a[i]] != cnt) {
                save[a[i]] = cnt;
                cur += a[i] < mid;
            }

            if (cur == mid) {
                cnt++;
                cur = 0;
            }
            // cout << "i: " << i << " cur: " << cur << " cnt: " << cnt << "\n";
        }

        if (cnt > k) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
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