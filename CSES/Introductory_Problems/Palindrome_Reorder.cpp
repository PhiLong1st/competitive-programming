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
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 'A']++;
    }
    int dem = 0;
    for (int i = 0; i < 30; i++)
    {
        dem += a[i] % 2;
    }
    if (dem <= 1)
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (i == 1)
                {
                    if (a[j] % 2 == 0)
                    {
                        for (int u = 1; u <= a[j] / 2; u++)
                        {
                            cout << (char)(j + 'A');
                        }
                    }
                }
                if (i == 2)
                {
                    if (a[j] % 2 != 0)
                    {
                        for (int u = 1; u <= a[j]; u++)
                        {
                            cout << (char)(j + 'A');
                        }
                    }
                }
            }
            if (i == 3)
            {
                for (int j = 30; j >= 0; j--)
                {
                    if (a[j] % 2 == 0)
                    {
                        for (int u = 1; u <= a[j] / 2; u++)
                        {
                            cout << (char)(j + 'A');
                        }
                    }
                }
            }
        }
    }
    else
    {
        cout << "NO SOLUTION";
    }
}
