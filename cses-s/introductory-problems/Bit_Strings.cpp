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
    ll n, tich = 1;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        tich *= (ll)2;
        tich %= MOD;
    }
    cout << tich;
}
