/*
    Code by: KoKoDuDu
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    cin >> s;
    ll dem = 0, kq = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            dem = 0;
        }
        else
        {
            dem++;
        }
        kq = max(kq, dem);
    }
    cout << kq + 1;
}
