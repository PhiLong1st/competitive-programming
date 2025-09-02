
/*
    Code by: KoKoDuDu
    Created: 24.12.2024 21:39:13
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, d;
    cin >> n >> d;
    set<int>ans;
    for (int i = 1; i <= 9; i += 2) {
        if (d % i == 0) {
            ans.insert(i);
        }
    }
    if (n >= 3) {
        ans.insert(3);
    }
    if (n >= 6) {
        ans.insert(9);
    }
    if (n >= 3 && d % 3 == 0) {
        ans.insert(9);
    }
    if (n >= 3) {
        ans.insert(7);
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
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