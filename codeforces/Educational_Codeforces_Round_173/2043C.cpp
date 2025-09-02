
/*
    Code by: KoKoDuDu
    Created: 24.12.2024 22:36:01
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int pos = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] != -1 && a[i] != 1) {
            pos = i;
        }
    }
    set<int> ans;
    if (pos == -1) {
        int minn = 0, maxx = 0;
        int sum_min = INF, sum_max = -INF;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += a[i];
            maxx = max(maxx, sum);
            minn = min(minn, sum);
            sum_min = min(sum_min, sum - maxx);
            sum_max = max(sum_max, sum - minn);
        }
        // cout << sum_min << ' ' << sum_max << '\n';
        ans.insert(0);
        for (int i = sum_min; i <= sum_max; ++i) {
            ans.insert(i);
        }
    }
    else {
        int minn = 0, maxx = 0;
        int sum_min = INF, sum_max = -INF;
        int sum = 0;
        for (int i = 1; i < pos; ++i) {
            sum += a[i];
            maxx = max(maxx, sum);
            minn = min(minn, sum);
            sum_min = min(sum_min, sum - maxx);
            sum_max = max(sum_max, sum - minn);
        }
        ans.insert(0);
        ans.insert(a[pos]);
        for (int i = sum_min; i <= sum_max; ++i) {
            ans.insert(i);
            // cout << i << ' ';
        }
        // cout << '\n';

        sum = 0;
        int minn1 = 0, maxx1 = 0;

        for (int i = pos - 1; i >= 1; --i) {
            sum += a[i];
            maxx1 = max(maxx1, sum);
            minn1 = min(minn1, sum);
        }
        sum = 0;
        int minn2 = 0, maxx2 = 0;
        for (int i = pos + 1; i <= n; ++i) {
            sum += a[i];
            maxx2 = max(maxx2, sum);
            minn2 = min(minn2, sum);
        }
        // cout << minn1 << ' ' << maxx1 << '\n';
        // cout << minn2 << ' ' << maxx2 << '\n';

        for (int i = minn1 + minn2 + a[pos]; i <= maxx1 + maxx2 + a[pos]; ++i) {
            ans.insert(i);
            // cout << i << ' ';
        }
        // cout << '\n';

        minn = 0, maxx = 0;
        sum_min = INF, sum_max = -INF;
        sum = 0;
        for (int i = pos + 1; i <= n; ++i) {
            sum += a[i];
            maxx = max(maxx, sum);
            minn = min(minn, sum);
            sum_min = min(sum_min, sum - maxx);
            sum_max = max(sum_max, sum - minn);
        }
        ans.insert(0);
        for (int i = sum_min; i <= sum_max; ++i) {
            ans.insert(i);
            // cout << i << ' ';
        }
        // cout << '\n';
    }
    cout << (int)ans.size() << '\n';
    for (int i : ans) {
        cout << i << ' ';
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