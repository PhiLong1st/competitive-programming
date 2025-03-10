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
    ll n, numTest;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = max(i - 6, 0); j < i; j++)
        {
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << "\n";
}