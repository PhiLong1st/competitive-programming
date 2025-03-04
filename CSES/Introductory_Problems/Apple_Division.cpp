/*
    Code by: KoKoDuDu

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 2e5 + 0307;
const ll MOD = 1e9 + 7;
ll save[maxN];
ll a[maxN], kq = 1e18;
void solve(ll dem, ll sz, ll a[])
{
    for (ll i = 0; i <= 1; i++)
    {
        save[dem] = i;
        if (dem < sz)
        {
            solve(dem + 1, sz, a);
        }
        else
        {
            ll sum = 0;
            ll tong = 0;
            for (ll j = 1; j <= sz; j++)
            {
                if (save[j] == 1)
                {
                    sum += a[j];
                }
                else
                {
                    tong += a[j];
                }
            }
            kq = min(kq, abs(tong - sum));
        }
    }
}
int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    solve(1, n, a);
    cout << kq;
}
