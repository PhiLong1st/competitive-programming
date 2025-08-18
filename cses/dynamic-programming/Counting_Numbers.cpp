/*
    Code by: KoKoDuDu
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
string convertToString(int x)
{
    string tmp = "";
    while (x > 0)
    {
        char c = (x % 10LL) + '0';
        x /= 10;
        tmp = c + tmp;
    }
    return tmp;
}
void solve()
{
    int l, r;
    cin >> l >> r;
    function<int(int x)> calc = [&](int x)
        {
            if (x < 0)
                return 0LL;
            string n = convertToString(x);
            int sz = n.size();
            vector3d(dp, sz + 5, 10LL, 3LL, int, 0);
            for (int i = 1; i <= 9; i++)
            {
                int state = 0;
                if (i == n[0] - '0')
                {
                    state = 1;
                }
                if (i > n[0] - '0')
                {
                    state = 2;
                }
                dp[1][i][state] = 1;
            }
            for (int i = 1; i < sz; i++)
            {
                for (int digit = 0; digit <= 9; digit++)
                {
                    for (int state = 0; state <= 2; state++)
                    {
                        if (dp[i][digit][state] == 0)
                            continue;
                        // cout << i << " " << digit << " " << state << "\n";
                        for (int d = 0; d <= 9; d++)
                        {
                            if (d == digit)
                                continue;
                            int nextState = state;
                            if (state == 1)
                            {
                                if (d < n[i] - '0')
                                    nextState = 0;
                                if (d > n[i] - '0')
                                    nextState = 2;
                            }
                            // cout << i << " " << digit << " " << state << " -> " << i + 1 << " " << d << " " << nextState << "\n";
                            dp[i + 1][d][nextState] += dp[i][digit][state];
                        }
                    }
                }
            }
            int ans = 0;
            for (int i = 1; i <= sz; i++)
            {
                for (int digit = 0; digit <= 9; digit++)
                {
                    int vt = (i == sz) ? 1LL : 2LL;
                    for (int state = 0; state <= vt; state++)
                    {
                        // cout << i << " " << digit << " " << state << "\n";
                        ans += dp[i][digit][state];
                    }
                }
            }
            return ans;
        };
    cout << calc(r) - calc(l - 1) + (l == 0);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--)
    {
        solve();
    }
    return 0;
}
