/*
    Code by: KoKoDuDu
*/
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define loop_up(i,a,b) for( ll i = a ; i <= b ; ++ i )
#define loop_down(i,a,b) for( ll i = b ; i >= a ; -- i )
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define IOFile(in,out) freopen(in, "r", stdin); freopen(out, "w", stdout);
using namespace std;
const ll maxN = 2e5 + 0307;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
vector<ll>adj[maxN];
ll child[maxN];
void dfs(ll x, ll par)
{
    if (adj[x].size() == 0)
    {
        child[x] = 1;
        return;
    }
    for (ll u : adj[x])
    {
        if (u == par) continue;
        dfs(u, x);
        child[x] += child[u];
    }
}
void solve()
{
    ll numNode;
    cin >> numNode;
    loop_up(i, 2, numNode)
    {
        ll x;
        cin >> x;
        adj[x].push_back(i);
    }
    loop_up(i, 1, numNode)
    {
        child[i] = 1;
    }
    dfs(1, -1);
    loop_up(i, 1, numNode)
    {
        cout << child[i] - 1 << " ";
    }
}
int main()
{
    //    IOFile("test.inp","test.out");
    fastio
        ll numTest = 1;
    while (numTest--)
    {
        solve();
    }
}
