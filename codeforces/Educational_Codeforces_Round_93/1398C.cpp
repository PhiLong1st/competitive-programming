/*
    Code by: KoKoDuDu
    Link: https://codeforces.com/problemset/problem/1398/C
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    map<int, int> cnt;
    vector<int> a(n + 1);
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + (s[i - 1] - '0');
        ans += cnt[a[i] - i];
        cnt[a[i] - i]++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}