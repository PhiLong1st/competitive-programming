#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e6 + 0307;
const ll MOD = 1e9 + 7;
ll a[maxN], dp[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll m, n, numTest;
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1e9;
    }
    for (int i = 1; i <= n; i++)
    {
        ll g = i;
        while (g != 0)
        {
            ll u = g % 10;
            // cout<<g%10<<" ";
            g /= 10;
            if (u != 0)
            {
                dp[i] = min(dp[i], dp[i - u] + 1);
            }
        }
        //cout<<"\n";
    }
    cout << dp[n];
}
