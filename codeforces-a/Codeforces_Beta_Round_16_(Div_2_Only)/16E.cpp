/*
    Code by: KoKoDuDu
    Link: https://codeforces.com/problemset/problem/16/E
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define pll pair<int, int>
#define pdb pair<db, db>
#define vector2d(name, sz1, sz2, type, val) vector<vector<type>> name(sz1, vector<type>(sz2, val))
#define vector3d(name, sz1, sz2, sz3, type, val) vector<vector<vector<type>>> name(sz1, vector<vector<type>>(sz2, vector<type>(sz3, val)))
#define vector4d(name, sz1, sz2, sz3, sz4, type, val) vector<vector<vector<vector<type>>>> name(sz1, vector<vector<vector<type>>>(sz2, vector<vector<type>>(sz3, vector<type>(sz4, val))))

const int MOD = 1e9 + 7;
const int INF = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector2d(a, n, n, db, 0.0);
    vector<db> dp((1 << n), 0.0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[(1 << n) - 1] = 1.0;
    for (int state = (1 << n) - 1; state >= 0; state--)
    {
        int cnt = __builtin_popcount(state);
        if (cnt == 1)
            continue;
        for (int i = 0; i < n; i++)
        {
            int maskA = (1 << i);
            if (!(maskA & state))
                continue;
            for (int j = 0; j < i; j++)
            {
                int maskB = (1 << j);
                if (!(maskB & state))
                    continue;
                dp[(state ^ maskA)] += dp[state] * a[j][i] * 2.0 / (1.0 * cnt * (cnt - 1.0));
                dp[(state ^ maskB)] += dp[state] * a[i][j] * 2.0 / (1.0 * cnt * (cnt - 1.0));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(6) << dp[(1 << i)] << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    // cin >> numTest;
    while (numTest--)
    {
        solve();
    }
    return 0;
}