/*
    Code by: KoKoDuDu

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 2e5 + 0307;
const ll MOD = 1e9 + 7;
vector<string>save[37];
int main()
{
    save[1].push_back("0");
    save[1].push_back("1");
    for (ll i = 2; i <= 16;i++)
    {
        for (ll j = 0; j < save[i - 1].size(); j++)
        {
            string t = save[i - 1][j] + "0";
            save[i].push_back(t);
        }
        for (ll j = save[i - 1].size() - 1; j >= 0; j--)
        {
            string t = save[i - 1][j] + "1";
            save[i].push_back(t);
        }
    }
    ll n;
    cin >> n;
    for (ll i = 0; i < save[n].size(); i++)
    {
        cout << save[n][i] << "\n";
    }
}
