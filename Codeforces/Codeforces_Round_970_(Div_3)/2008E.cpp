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
    string s;
    cin >> s;

    vector3d(prefix, 2, 26, n + 3, int, 0);
    vector3d(suffix, 2, 26, n + 3, int, 0);

    for (int i = 1; i <= n; i++)
    {
        prefix[i % 2][s[i - 1] - 'a'][i] = 1;
        for (int j = 0; j < 26; ++j)
        {
            prefix[0][j][i] += prefix[0][j][i - 1];
            prefix[1][j][i] += prefix[1][j][i - 1];
        }
    }

    for (int i = n; i >= 1; i--)
    {
        suffix[i % 2][s[i - 1] - 'a'][i] = 1;
        for (int j = 0; j < 26; ++j)
        {
            suffix[0][j][i] += suffix[0][j][i + 1];
            suffix[1][j][i] += suffix[1][j][i + 1];
        }
    }
    if (n % 2 == 0)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int maxR1 = 0, maxR2 = 0, maxR3 = 0, maxR4 = 0;
            for (int j = 0; j < 26; ++j)
            {
                maxR3 = max(maxR3, prefix[i % 2][j][i] + suffix[i % 2][j][i + 1]);
                maxR4 = max(maxR4, prefix[(i % 2) ^ 1][j][i] + suffix[(i % 2) ^ 1][j][i + 1]);
            }
            ans = max({ ans, maxR3 + maxR4 });
        }
        cout << n - ans << '\n';
    }
    else
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int maxR1 = 0, maxR2 = 0, maxR3 = 0, maxR4 = 0;
            for (int j = 0; j < 26; ++j)
            {
                maxR1 = max(maxR1, prefix[i % 2][j][i - 1] + suffix[(i % 2) ^ 1][j][i + 1]);
                maxR2 = max(maxR2, prefix[(i % 2) ^ 1][j][i - 1] + suffix[i % 2][j][i + 1]);
            }
            ans = max({ ans, maxR1 + maxR2 });
        }
        cout << n - ans << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCount;
    cin >> testCount;
    while (testCount--)
    {
        solve();
    }
    return 0;
}
