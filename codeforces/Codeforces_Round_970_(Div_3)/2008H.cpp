/*
    Code by: KoKoDuDu
    Created: 03.01.2025 14:33:02
    Link: https://codeforces.com/problemset/problem/2008/H
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> cnt(n + 1), ans(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; ++i) {
        cnt[i] += cnt[i - 1];
    }
    int median = (n + 2 - (n % 2)) / 2;
    while (q--) {
        int x;
        cin >> x;
        if (ans[x] == -1) {
            int l = 0, r = x - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int l_1 = 0, r_1 = mid;
                int tmp = 0;
                bool isOk = false;
                int val = 1 + (n - r_1 + x - 1) / x;
                while (val--) {
                    if (l_1 > r_1) break;
                    tmp += cnt[r_1] - (l_1 == 0 ? 0 : cnt[l_1 - 1]);
                    l_1 += x;
                    r_1 += x;
                    r_1 = min(n, r_1);
                }
                if (tmp >= median) {
                    ans[x] = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        cout << ans[x] << ' ';
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