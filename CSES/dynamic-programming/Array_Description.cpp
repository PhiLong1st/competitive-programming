#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 1e5 + 0307;
const ll MOD = 1e9 + 7;
ll a[maxN], n, m;
ll dp[maxN][307];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[1] == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[1][i] = 1;
        }
    }
    else
    {
        dp[1][a[1]] = 1;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            //            if(a[i-1]==0)
            //            {
            //
            //            }
            //            else
            {
                for (ll j = 1; j <= m; j++)
                {
                    dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
                    dp[i][j] %= MOD;
                }
            }
        }
        else
        {
            if (a[i - 1] == 0)
            {
                for (ll j = max((ll)1, a[i] - 1); j <= min(m, a[i] + 1); j++)
                {
                    dp[i][a[i]] += dp[i - 1][j];
                    dp[i][a[i]] %= MOD;
                }
            }
            else
            {
                if (abs(a[i] - a[i - 1]) <= 1)
                {
                    dp[i][a[i]] += dp[i - 1][a[i - 1]];
                    dp[i][a[i]] %= MOD;
                }
            }
        }
    }
    ll kq = 0;
    for (ll i = 1; i <= m; i++)
    {
        kq += dp[n][i];
        kq %= MOD;
    }
    cout << kq;
}
