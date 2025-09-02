
/*
    Code by: KoKoDuDu
    Created: 01.11.2024 21:51:04
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == k) {
        if (n == 1) {
            cout << 1 << '\n' << 1 << '\n';
        }
        else {
            return void(cout << -1 << '\n');
        }
    }
    else {
        if (k == 1) {
            return void(cout << -1 << '\n');
        }
        if (k % 2 == 0) {
            cout << 3 << '\n';
            cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
        }
        else {
            cout << 5 << '\n';
            cout << 1 << ' ' << k - 1 << ' ' << k << ' ' << k + 1 << ' ' << k + 2 << '\n';
        }
    }
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