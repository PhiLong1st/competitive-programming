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
    ll n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i != 1)
        {
            sum += max((ll)0, a[i - 1] - a[i]);
        }
        a[i] += max((ll)0, a[i - 1] - a[i]);
    }
    cout << sum;
}