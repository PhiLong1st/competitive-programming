#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 0307;
int a[maxN];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int dem = 0;
    for (int i = 100; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            dem++;
            if (dem == 2)
            {
                cout << i;
                return 0;
            }
        }
    }
}
