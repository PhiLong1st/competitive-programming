
/*
    Code by: KoKoDuDu
    Created: 26.11.2024 12:00:56
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
struct Number_Theory {
    int inverse(int i, int MOD) {
        if (i == 1) return 1;
        return (MOD - ((MOD / i) * inverse(MOD % i, MOD)) % MOD + MOD) % MOD;
    }
    int mod_exp(int n, int x, int MOD) {
        int res = 1;
        while (x > 0) {
            if (x & 1) {
                res = (res * n) % MOD;
            }
            n = (n * n) % MOD;
            x >>= 1;
        }
        return res;
    }
    bool check_perfect_square(int n) {
        int t = sqrt(n);
        return t * t == n;
    }
};

void solve() {
    int n;
    cin >> n;
    Number_Theory nb;
    int cnt_div = 1, sum_div = 1, mul_div = 0, tich = 1, number = 1, flag = 0;
    int sqrt_n = 1;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        cnt_div *= (y + 1) % MOD;
        cnt_div %= MOD;
        sum_div *= (nb.mod_exp(x, y + 1, MOD) - 1 + MOD) % MOD * nb.inverse(x - 1, MOD) % MOD;
        sum_div %= MOD;
        number *= nb.mod_exp(x, y, MOD);
        number %= MOD;
        sqrt_n *= nb.mod_exp(x, y / 2, MOD);
        sqrt_n %= MOD;
        if (y % 2 == 1 && flag == 0) {
            tich *= ((y + 1) / 2);
            tich %= (MOD - 1);
            flag = 1;
        }
        else {
            tich *= (y + 1) % (MOD - 1);
            tich %= (MOD - 1);
        }
    }
    mul_div = nb.mod_exp(number, tich, MOD);
    if (!flag) {
        mul_div = nb.mod_exp(sqrt_n, tich, MOD);
        mul_div %= MOD;
    }
    cout << cnt_div << ' ' << sum_div << ' ' << mul_div << '\n';
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