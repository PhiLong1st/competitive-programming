/*
    Code by: KoKoDuDu
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 2e5 + 0307;
const ll MOD = 1e9 + 7;
ll save[maxN];
ll a[maxN], tich[maxN];
ll numPos(ll u, ll pos)
{
    string s = to_string(u);
    return s[pos - 1] - '0';
}
int main()
{
    ll numTest, k;
    cin >> numTest;
    tich[1] = 1;
    for (ll i = 1; i < 18; i++)
    {
        if (i != 1)
        {
            tich[i] = tich[i - 1] * 10;
        }
        a[i] = i * 9 * tich[i];
        a[i] += a[i - 1];
        // cout<<a[i]<<" ";
    }
    while (numTest--)
    {
        cin >> k;
        for (ll i = 1; i <= 18; i++)
        {
            if (k <= a[i])
            {
                k -= a[i - 1];
                if (k % i == 0)
                {
                    cout << (tich[i] + k / i - 1) % 10 << "\n";
                }
                else
                {
                    ll u = tich[i] + k / i;
                    //cout<<i<<" "<<k<<" "<<u<<" "<<numPos(u,k%i)<<"\n";
                    cout << numPos(u, k % i) << "\n";
                }
                break;
            }
        }
    }
}
