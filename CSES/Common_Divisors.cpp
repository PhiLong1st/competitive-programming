
/*
    Code by: KoKoDuDu
    Created: 29.10.2024 19:41:44
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(1000010);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= 1000000; ++i) {
        int cnt = 0;
        for (int j = i; j <= 1000000; j += i) {
            cnt += a[j];
        }
        if (cnt > 1) {
            ans = max(ans, i);
        }
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}