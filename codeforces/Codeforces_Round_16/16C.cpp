/*
    Code by: KoKoDuDu
    Link: https://codeforces.com/problemset/problem/16/C/
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pll pair<int, int>
const int MOD = 1e9 + 7;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int t = gcd(x, y);
    x /= t;
    y /= t;
    int l = 1, r = min(a / x, b / y);
    pll ans = { 0,0 };
    cout << x * r << ' ' << y * r;
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