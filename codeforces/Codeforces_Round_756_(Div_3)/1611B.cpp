/*
    Code by: KoKoDuDu
    Created: 17.02.2025 13:35:40
    Link: https://codeforces.com/problemset/problem/1611/B
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    int dif = min((b - a) / 2, a);
    a -= dif, b -= 3 * dif;
    cout << dif + a / 2 << '\n';
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