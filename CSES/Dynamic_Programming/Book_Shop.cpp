#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e6 + 0307;
const ll MOD = 1e9 + 7;
ll a[maxN], dp[maxN], b[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll m, n, x, numTest;
    cin >> n >> x;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            if (j < a[i])
            {
                continue;
            }
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            if (dp[j] >= MOD)
            {
                dp[j] -= MOD;
            }
        }
    }
    cout << dp[x];
}
