/*
    Code by: KoKoDuDu
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 2e5 + 0307;
ll a[maxN];
int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        a[i] = max((ll)0, a[i - 1] + 2 * (i - 1 + i - 2) - 2);
        cout << i * i * (i * i - 1) / 2 - 2 * a[i] << "\n";
    }
}