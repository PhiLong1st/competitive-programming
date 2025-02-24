
/*
    Code by: KoKoDuDu
    Created: 02.11.2024 14:36:48
    Link: https://oj.vnoi.info/problem/dtl24_b
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> cnt;
    vector<int>save;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] == 1) {
            save.push_back(a[i]);
        }
    }
    int ans = INF, sum = 0;
    sort(save.begin(), save.end());
    for (int i = save.size() - 1; i >= 0; i--) {
        int val = max(0LL, k - cnt[save[i]]);
        if (sum >= val) {
            ans = min(ans, val);
        }
        sum += cnt[save[i]];
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