/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<int, int> pre, suf;
    vector<int> arr(n + 1), a(n + 1), b(n + 2);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (pre[arr[i]] == 0) {
            a[i]++;
        }
        a[i] += a[i - 1];
        pre[arr[i]] += 1;
    }

    for (int i = n; i >= 1; --i) {
        if (suf[arr[i]] == 0) {
            b[i]++;
        }
        b[i] += b[i + 1];
        suf[arr[i]] += 1;
    }

    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans = max(ans, a[i - 1] + b[i]);
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