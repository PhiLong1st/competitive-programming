/*
    Code by: KoKoDuDu
    Created: 2025.04.08 22:20:51
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

int arr[3][3] = {
    {0, 0, 0},
    {0, 1, 4},
    {0, 3, 2},
};

int cal(int x, int y, int n)
{
    if (n == 1) {
        return arr[x][y];
    }

    int val = (1 << (n - 1));
    int xx = (x > val) ? x - val : x;
    int yy = (y > val) ? y - val : y;

    int bonus = 0;
    if (x <= val && y <= val) { // 1
        bonus = 0;
    }
    else if (x > val && y > val) { // 2
        bonus = val * val;
    }
    else if (x > val && y <= val) { // 3
        bonus = 2 * val * val;
    }
    else { // 4
        bonus = 3 * val * val;
    }
    return bonus + cal(xx, yy, n - 1);
}

pll sol(int x, int n)
{
    if (x == 1) {
        return pll(1, 1);
    }
    if (x == 2) {
        return pll(2, 2);
    }
    if (x == 3) {
        return pll(2, 1);
    }
    if (x == 4) {
        return pll(1, 2);
    }

    int val = (1 << (n - 1));

    if (1 <= x && x <= val * val) { // 1
        auto [a, b] = sol(x, n - 1);
        return pll(a, b);
    }
    else if (1 + val * val <= x && x <= 2 * val * val) { // 2
        auto [a, b] = sol(x - val * val, n - 1);
        return pll(a + val, b + val);
    }
    else if (1 + 2 * val * val <= x && x <= 3 * val * val) { // 3
        auto [a, b] = sol(x - 2 * val * val, n - 1);
        return pll(a + val, b);
    }
    else { // 4
        auto [a, b] = sol(x - 3 * val * val, n - 1);
        return pll(a, val + b);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        string c;
        int x, y;
        cin >> c;
        if (c == "->") {
            cin >> x >> y;
            cout << cal(x, y, n) << '\n';
        }
        else {
            cin >> x;
            auto [a, b] = sol(x, n);
            cout << a << ' ' << b << '\n';
        }
    }
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