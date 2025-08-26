#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 0307;
int a[maxN];
int n, m;
int main()
{
    cin >> n >> m;
    int maxx = 0;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        a[x]++;
        if (x < maxx && a[x] == a[maxx])
        {
            maxx = x;
        }
        if (a[x] > a[maxx])
        {
            maxx = x;
        }
        cout << maxx << "\n";
    }
}
