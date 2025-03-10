#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e3 + 0307;
const ll MOD = 1e9 + 7;
ll dp[maxN][maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        swap(a, b);
    }
    dp[1][1] = 0;
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            dp[i][j] = 1e9;
        }
        dp[i][i] = 0;
    }
    for (int i = 1; i <= a; i++)
    {
        dp[i][1] = i - 1;
        dp[1][i] = i - 1;
    }
    //    for( int i = 1 ; i <= a ; i ++ )
    //    {
    //        for( int j = 1 ; j <= b ; j ++ )
    //        {
    //            cout<<dp[i][j]<<" ";
    //        }
    //        cout<<"\n";
    //    }
    for (int i = 1; i <= a; i++)
    {
        dp[i][i] = 0;
        for (int j = 1; j <= b; j++)
        {
            for (int u = 1; u < i; u++)
            {
                dp[i][j] = min(dp[i][j], dp[i - u][j] + dp[u][j] + 1);
            }
            for (int u = 1; u < j; u++)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - u] + dp[i][u] + 1);
            }
            dp[j][i] = dp[i][j];
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
        }
        //   cout<<"\n";
    }
    cout << dp[a][b];
}
