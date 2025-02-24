/*
    Code by: KoKoDuDu
    Created: 23.09.2024 16:10:47
    Link: https://oj.vnoi.info/problem/olp_kc19_cow
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
const int MOD = 1e9 + 7;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        int squareDist = ((x - a) * (x - a) + (y - b) * (y - b));
        int dist = sqrt(squareDist);
        dist -= (dist * dist == squareDist);
        ans = min(ans, dist - r);
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--) {
        solve();
    }
    return 0;
}