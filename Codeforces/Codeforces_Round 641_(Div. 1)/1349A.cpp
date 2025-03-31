/*
    Code by: KoKoDuDu

*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int MAX_N = 2e5 + 0307;

void solve() {
    int n;
    int ans = 1;
    cin >> n;
    vector<int> a(n), sieve;
    vector<int> save(MAX_N + 1), min_mul(MAX_N + 1, INT_MAX);

    for (auto& x : a) {
        cin >> x;
    }

    for (int i : a) {
        int x = i;
        for (int j = 2; j * j <= i; ++j) {
            if (x == 1) {
                break;
            }

            int u = j, v = u / j;
            int cnt = 0;

            save[j] += (x % j == 0);
            while (x % j == 0) {
                cnt++;
                x /= j;
                min_mul[j] = min(min_mul[j], cnt);
            }

            cnt = 0;
            save[j] += (x % j == 0);
            while (x % j == 0) {
                cnt++;
                x /= j;
                min_mul[j] = min(min_mul[j], cnt);
            }
        }
    }
    for (int i = 2; i <= 20; ++i) {
        int x = save[i];
        cout << i << ' ';
        cout << x << ' ' << min_mul[i] << '\n';
        // if (x == n - 1) {
        //     // ans *= min_mul[x];
        // }
        // if (x == n) {
        //     // ans *= min_mul[x];
        // }
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