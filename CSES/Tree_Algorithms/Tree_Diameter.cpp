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
ll dist[maxN], dist2[maxN];
void dfs(ll x, ll par)
{
    for (ll g : adj[x])
    {
        if (g == par) continue;
        dist[g] = dist[x] + 1;
        dfs(g, x);
    }
}
void dfs2(ll x, ll par)
{
    for (ll g : adj[x])
    {
        if (g == par) continue;
        dist2[g] = dist2[x] + 1;
        dfs2(g, x);
    }
}
void solve()
{
    ll numNode;
    cin >> numNode;
    loop_up(i, 1, numNode - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    ll pos = 1;
    loop_up(i, 1, numNode)
    {
        //        cout<<dist[i]<<" ";
        if (dist[pos] < dist[i])
        {
            pos = i;
        }
    }
    //    cout<<pos;
    dfs2(pos, -1);
    cout << *max_element(dist2 + 1, dist2 + numNode + 1);
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
