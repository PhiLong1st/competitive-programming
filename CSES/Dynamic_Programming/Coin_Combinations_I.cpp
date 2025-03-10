#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 1e6 + 0307;
const ll MOD = 1e9 + 7;
ll a[maxN], dp[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll m, n, numTest;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - a[j] >= 0)
            {
                if (dp[i - a[j]] != 0)
                {
                    dp[i] += dp[i - a[j]];
                    dp[i] %= MOD;
                }

            }
        }
        // cout<<dp[i]<<" ";
    }
    cout << dp[m] << "\n";
}
