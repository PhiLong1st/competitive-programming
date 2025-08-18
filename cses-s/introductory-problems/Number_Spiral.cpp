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
    ll numTest, x, y;
    cin >> numTest;
    while (numTest--)
    {
        cin >> x >> y;
        if (x > y)
        {
            if (x % 2 == 0)
            {
                cout << x * x - y + 1 << "\n";
            }
            else
            {
                cout << (x - 1) * (x - 1) + y << "\n";
            }
        }
        else
        {
            if (y % 2 != 0)
            {
                cout << y * y - x + 1 << "\n";
            }
            else
            {
                cout << (y - 1) * (y - 1) + x << "\n";
            }
        }
    }
}