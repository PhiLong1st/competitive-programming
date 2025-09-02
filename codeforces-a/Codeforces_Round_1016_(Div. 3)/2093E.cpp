/*
    Code by: KoKoDuDu
    Created: 2025.04.08 23:10:52
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int l = 0, r = n + 1, ans = 0;
    unordered_map<int, int, custom_hash> save;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        save.clear();
        int cnt = 1, cur = 0;

        for (int i = 1; i <= n; ++i) {
            if (save[a[i]] != cnt) {
                save[a[i]] = cnt;
                cur += a[i] < mid;
            }

            if (cur == mid) {
                cnt++;
                cur = 0;
            }
        }

        if (cnt > k) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
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