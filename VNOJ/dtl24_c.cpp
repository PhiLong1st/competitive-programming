
/*
    Code by: KoKoDuDu
    Created: 02.11.2024 14:59:23
    Link: https://oj.vnoi.info/problem/dtl24_c
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int pos = 0;
    for (int i = 30; i >= 0; --i) {
        if ((n & (1LL << i))) {
            pos = i;
            break;
        }
    }
    // cout << pos << ' ';
    cout << (n * (1LL << (pos + 1))) << ' ' << n + (n * (1LL << (pos + 1))) << '\n';
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