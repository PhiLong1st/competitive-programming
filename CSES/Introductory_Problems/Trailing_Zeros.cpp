/*
    Code by: KoKoDuDu
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 2e5 + 0307;
const ll MOD = 1e9 + 7;
ll a[maxN];
int main()
{
    ll n;
    cin >> n;
    ll pl = 0, pm = 0;
    ll t = 2;
    while (t <= n)
    {
        pl += n / t;
        t *= 2;
    }
    t = 5;
    while (t <= n)
    {
        pm += n / t;
        t *= 5;
    }
    cout << min(pl, pm);
}
