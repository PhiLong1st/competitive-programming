/*
    Code by: KoKoDuDu
    Created: 02.12.2024 18:31:59
    Link: https://oj.vnoi.info/problem/mskycode
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n + 1), d(10010);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            int x = a[i];
            for (int j = 1; j * j <= x; ++j) {
                if (x % j == 0) {
                    if (j * j != x) {
                        d[x / j]++;
                    }
                    d[j]++;
                }
            }
        }
        for (int i = 10000; i >= 1; --i) {
            d[i] = d[i] * (d[i] - 1) * (d[i] - 2) * (d[i] - 3) / 24;
            for (int j = 2 * i; j <= 10000; j += i) {
                d[i] -= d[j];
            }
        }
        cout << d[1] << '\n';
    }
    return 0;
}