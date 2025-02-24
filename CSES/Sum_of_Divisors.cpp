/*
    Code by: KoKoDuDu
    Created: 31.10.2024 07:22:24
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

int inverse(int i) {
    if (i == 1) return 1;
    return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; ++i) {
        ans += i * (n / i) % MOD;
        ans %= MOD;
    }
    int l = sqrt(n);
    for (int i = sqrt(n); i >= 1; --i) {
        int r = n / i;
        int sum = 0;
        sum += (r % MOD) * ((r + 1) % MOD) % MOD * inverse(2) % MOD;
        sum %= MOD;
        sum -= (l % MOD) * ((l + 1) % MOD) % MOD * inverse(2) % MOD;
        sum = (sum + MOD) % MOD;
        sum = sum * i % MOD;
        ans = (ans + sum) % MOD;
        l = r;
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