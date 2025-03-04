/*
    Code by: KoKoDuDu
    Created: 24.12.2024 23:17:56
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
const int MOD = 1e9 + 7;

void solve() {
    int l, r, g;
    cin >> l >> r >> g;
    int maxx = -1;
    int best_x = -1, best_y = -1;
    int x = (l + g - 1) / g, y = r / g;
    for (int i = x; i <= min(x + 30, y); ++i) {
        for (int j = y; j >= max(y - 30, x); --j) {
            if (__gcd(i, j) == 1) {
                // cout << i * g << ' ' << j * g << '\n';
                if (maxx < abs(i * g - j * g)) {
                    maxx = max(maxx, abs(i * g - j * g));
                    best_x = i * g;
                    best_y = j * g;
                }
            }
        }
    }
    cout << best_x << ' ' << best_y << '\n';
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