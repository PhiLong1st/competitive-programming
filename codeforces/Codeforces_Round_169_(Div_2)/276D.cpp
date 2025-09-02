/*
    Code by: KoKoDuDu
    Created: 03.02.2025 09:15:56
    Link: https://codeforces.com/problemset/problem/276/D
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
void solve()
{
    int a, b;
    cin >> a >> b;

    // Sol 1
    for (int bit = 60; bit >= 0; --bit)
    {
        if (!(a & (1LL << bit)) && (b & (1LL << bit)))
        {
            cout << (1LL << (bit + 1)) - 1;
            return;
        }
    }
    cout << 0;

    // Sol 2
    // int ans = 0;
    // int dist = b - a;
    // int bit = 0;
    // while ((1LL << bit) <= dist) {
    //     ans ^= (1LL << bit);
    //     ++bit;
    // }
    // while ((1LL << bit) <= b) {
    //     if (((a & (1LL << bit)) != (b & (1LL << bit)))) {
    //         ans ^= (1LL << bit);
    //     }
    //     ++bit;
    // }
    // cout << ans;
}

int32_t main()
{
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