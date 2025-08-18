#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 1e6 + 0307;
const ll MOD = 1e9 + 7;
ll a[maxN], dp[maxN][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    dp[1][1] = dp[1][2] = 1;
    ll n, numTest;
    for (int i = 2; i <= 1000000; i++)
    {
        dp[i][1] = 4 * dp[i - 1][1] % MOD + dp[i - 1][2];
        dp[i][1] %= MOD;
        dp[i][2] = 2 * dp[i - 1][2] % MOD + dp[i - 1][1];
        dp[i][2] %= MOD;
    }
    //    cout<<(dp[n][1]+dp[i][2])%MOD;
    cin >> numTest;
    while (numTest--)
    {
        cin >> n;
        cout << (dp[n][1] + dp[n][2]) % MOD << "\n";
    }
}