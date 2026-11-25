/*
    Code by: KoKoDuDu
    Link: https://codeforces.com/problemset/problem/2032/C
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0, ans = n - 2;
    for (int r = 2; r < n; r++) {
        while (r - l >= 2 && a[l] + a[l + 1] <= a[r]) l++;
        ans = min(ans, n - (r - l + 1));
    }
    cout << ans << "\n";
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