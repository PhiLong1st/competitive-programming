/*
    Code by: KoKoDuDu
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 2e5 + 0307;
const ll MOD = 1e9 + 7;
void solve(ll n, ll a, ll b, ll c)
{
    if (n == 1)
    {
        cout << a << " " << c << "\n";
        return;
    }
    solve(n - 1, a, c, b);
    cout << a << " " << c << "\n";
    solve(n - 1, b, a, c);
}
int main()
{
    ll n;
    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    solve(n, 1, 2, 3);
}
