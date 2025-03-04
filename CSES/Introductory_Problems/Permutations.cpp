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
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (n <= 3)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        if (n % 2 != 0)
        {
            cout << n << " ";
            n--;
        }
        for (int i = n / 2; i >= 1; i--)
        {
            cout << i << " " << i + n / 2 << " ";
        }
    }
}