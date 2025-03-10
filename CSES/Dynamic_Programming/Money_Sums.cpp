#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e6 + 0307;
const ll MOD = 1e9 + 7;
ll dp[maxN], a[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll n;
    ll sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= 0; j--)
        {
            if (j - a[i] >= 0)
            {
                dp[j] += dp[j - a[i]];
            }
        }
    }
    ll kq = 0;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i] != 0)
        {
            kq++;
            //cout<<i<<" ";
        }
    }
    cout << kq << "\n";
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i] != 0)
        {
            cout << i << " ";
        }
    }
}
