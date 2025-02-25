/*
    Code by: KoKoDuDu

*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    if (abs(n * p) < abs(k)) {
        cout << -1 << '\n';
        return;
    }
    cout << (abs(k) + abs(p) - 1) / abs(p) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}