/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

bool checkPower(int n) {
    if (n == 0) return false;
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}
void calc(int n, int k) {
    if (checkPower(n)) {
        for (int i = 1; i <= n; ++i) {
            cout << k << ' ';
        }
        return;
    }
    if (checkPower(n + 1)) {
        for (int i = 1; i <= n; ++i) {
            cout << ((i % 2) ? k : 0) << ' ';
        }
        return;
    }
    int bit = 31;
    for (int i = 31; i >= 0; --i) {
        if ((n & (1LL << i))) {
            bit = i;
            break;
        }
    }
    int m = n ^ (1LL << bit);
    calc(m, k);
    for (int i = 1; i <= n - 2 * m; ++i) {
        cout << 0 << ' ';
    }
    calc(m, k);
}
void solve() {
    int n, k;
    cin >> n >> k;
    calc(n, k);
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