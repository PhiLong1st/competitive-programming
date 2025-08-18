#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 1e6 + 0307;
const ll MOD = 1e9 + 7;
ll kq = 0;
ll dp[maxN];
ll lt(ll cs, ll mu)
{
    if (mu == 1)
    {
        return cs;
    }
    if (mu == 0)
    {
        return 1;
    }
    ll g = lt(cs, mu / 2);
    if (mu % 2 == 0)
    {
        return (g * g) % MOD;
    }
    else
    {
        return ((g * g) % MOD * cs) % MOD;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = sum / 2; j >= 0; j--)
        {
            if (j - i >= 0)
            {
                dp[j] += dp[j - i];
                if (dp[j] >= MOD)
                {
                    dp[j] %= MOD;
                }
            }
        }
    }
    cout << (dp[sum / 2] * lt(2, MOD - 2)) % MOD;
}
