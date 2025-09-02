
/*
    Code by: KoKoDuDu
    Created: 01.11.2024 21:38:22
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    int cnt_1 = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> a[i];
        cnt_1 += (a[i] == 1);
    }
    cout << cnt_1 % 2 << ' ' << min(n - max(0LL, cnt_1 - n), cnt_1) << '\n';

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