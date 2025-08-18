#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 5e3 + 0307;
const ll MOD = 1e9 + 7;
ll kq = 0;
ll a[maxN], dp[maxN][maxN];
ll solve(ll l, ll r, ll check)
{
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    if (l == r)
    {
        if (check == 1)
        {
            return a[l];
        }
        else
        {
            return 0;
        }
    }

    if (l < r)
    {
        if (check == 0)
        {
            ll u = solve(l + 1, r, 1 - check);
            ll v = solve(l, r - 1, 1 - check);
            dp[l][r] = min(u, v);
            return dp[l][r];
        }
        else
        {
            ll u = solve(l + 1, r, 1 - check) + a[l];
            ll v = solve(l, r - 1, 1 - check) + a[r];
            dp[l][r] = max(u, v);
            return dp[l][r];
        }
    }
    else
    {
        return 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll n;
    ifstream fi("input.txt");
    //  fi>>n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        //fi>>a[i];
        cin >> a[i];
    }
    cout << solve(1, n, 1) << "\n";
}