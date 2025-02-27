/*
    Code by: KoKoDuDu
    Link: https://codeforces.com/problemset/problem/729/C/
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<int> b(k + 1);
    vector<pll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= k; ++i) {
        cin >> b[i];
    }
    b.push_back(s);
    int l = 1, r = 1e9, min_fuel = -1;
    sort(b.begin() + 1, b.end());
    while (l <= r) {
        int mid = (l + r) >> 1;
        int total = 0;
        bool ok = true;
        for (int i = 1; i < b.size(); ++i) {
            int dist = b[i] - b[i - 1];
            if (dist > mid) {
                ok = false;
                break;
            }
            total += 2 * dist - min(dist, mid - dist);
        }
        if (!ok || total > t) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
            min_fuel = mid;
        }
    }
    int ans = INF;
    if (min_fuel == -1) {
        cout << -1;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i].second >= min_fuel) {
            ans = min(ans, a[i].first);
        }
    }
    cout << ((ans == INF) ? -1 : ans);
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