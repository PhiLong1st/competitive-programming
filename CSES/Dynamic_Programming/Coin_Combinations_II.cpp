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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] > j)
            {
                continue;
            }
            dp[j] += dp[j - a[i]];
            if (dp[j] >= MOD)
            {
                dp[j] -= MOD;
            }
        }
    }
    cout << dp[m];
}