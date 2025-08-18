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
    if (n * (n + 1) % 4 == 0)
    {
        cout << "YES\n";
        if (n % 2 == 0)
        {
            cout << n / 2 << "\n";
            ll l = 1;
            ll r = n;
            while (l < r)
            {
                cout << l << " " << r << " ";
                l += 2;
                r -= 2;
            }
            cout << "\n" << n / 2 << "\n";
            l = 2;
            r = n - 1;
            while (l < r)
            {
                cout << l << " " << r << " ";
                l += 2;
                r -= 2;
            }
        }
        else
        {
            cout << n / 2 + 1 << "\n";
            cout << 1 << " " << n - 1 << " ";
            ll l = 2;
            ll r = n - 2;
            while (l < r)
            {
                cout << l << " " << r << " ";
                l += 2;
                r -= 2;
            }
            cout << "\n" << n / 2 << "\n";
            cout << n << " ";
            l = 3;
            r = n - 3;
            while (l < r)
            {
                cout << l << " " << r << " ";
                l += 2;
                r -= 2;
            }
        }
    }
    else
    {
        cout << "NO";
    }
}
