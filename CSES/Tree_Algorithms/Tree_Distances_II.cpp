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
ll dist[maxN], numChild[maxN], distChild[maxN], distPar[maxN];
ll dem;
void dfs(ll x, ll par)
{
    dem++;
    ll tmp_child = dem;
    for (ll g : adj[x])
    {
        if (g == par) continue;
        dist[g] = dist[x] + 1;
        dfs(g, x);
        numChild[x] = dem - tmp_child;
        distChild[x] += distChild[g] + numChild[g] + 1;
    }
}
void dfs(ll x, ll par, ll sumPar)
{
    distPar[x] = sumPar;
    ll sum = 0;
    for (ll g : adj[x])
    {
        if (g == par) continue;
        sum += distChild[g] + numChild[g] + 1;
    }
    //    cout<<x<<" "<<sum<<"a\n";
    for (ll g : adj[x])
    {
        if (g == par) continue;
        dfs(g, x, sumPar + sum - distChild[g] - numChild[g] + numChild[1] - 1 - numChild[g]);
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
    dfs(1, -1, 0);
    loop_up(i, 1, numNode)
    {
        //        cout<<dist[i]<<" "<<numChild[i]<<" "<<distChild[i]<<" "<<distPar[i]<<"\n";
        cout << distChild[i] + distPar[i] << " ";
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
