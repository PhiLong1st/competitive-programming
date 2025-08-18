/*
    Code by: KoKoDuDu
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxN = 1e3 + 0307;
ll a[maxN], n, x;
void solve(ll l, ll r, ll pos, vector<ll>& tmp, ll sum)
{
    tmp.push_back(sum);

    for (int i = pos; i <= n; i++)
    {
        if (i >= l && i <= r)
        {
            solve(l, r, i + 1, tmp, sum + a[i]);
        }
    }
}
int main()
{
    ll kq = 0;
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<ll>first, second;
    solve(1, n / 2, 1, first, 0);
    solve(n / 2 + 1, n, n / 2 + 1, second, 0);
    sort(second.begin(), second.end());

    for (ll val : first)
    {
        ll u = lower_bound(second.begin(), second.end(), x - val) - second.begin();
        ll v = upper_bound(second.begin(), second.end(), x - val) - second.begin();
        kq += v - u;
    }

    cout << kq;
}
