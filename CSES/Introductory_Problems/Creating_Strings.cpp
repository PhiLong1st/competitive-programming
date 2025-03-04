/*
    Code by: KoKoDuDu
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 2e5 + 0307;
const ll MOD = 1e9 + 7;
set<string>save;
ll a[maxN];
int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    for (ll i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    do
    {
        string tmp = "";
        for (ll i = 1; i <= n; i++)
        {
            // cout<<a[i]<<" ";
            tmp += s[a[i] - 1];
        }
        save.insert(tmp);
        //cout<<tmp<<"\n";
    } while (next_permutation(a + 1, a + n + 1));
    cout << save.size() << "\n";
    for (string i : save)
    {
        cout << i << "\n";
    }
}
