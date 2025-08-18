#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e3 + 0307;
const ll MOD = 1e9 + 7;
ll dp[maxN][maxN];
char a[maxN][maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll m, n, numTest;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    if (a[1][1] == '.')
    {
        dp[1][1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == '.')
            {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                if (dp[i][j] >= MOD)
                {
                    dp[i][j] -= MOD;
                }
            }
            //  cout<<dp[i][j]<<" ";
        }
        // cout<<"\n";
    }
    cout << dp[n][n];
}