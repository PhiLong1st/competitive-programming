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
    ll numTest;
    cin >> numTest;
    while (numTest--)
    {
        ll x, y;
        cin >> x >> y;
        ll a = y - (4 * y - 2 * x) / 3;
        ll b = (2 * y - x) / 3;
        if (a >= 0 && b >= 0 && 2 * a + b == x && a + 2 * b == y)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
