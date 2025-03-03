#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, m, d;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> d;
        if (n < m)
        {
            swap(n, m);
        }
        if (n > m * (d + 1))
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES" << "\n";
        }
    }
}
