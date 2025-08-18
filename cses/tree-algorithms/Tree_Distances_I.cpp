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
ll distChild[maxN], distPar[maxN];
void dfs(ll x, ll par)
{
    for (ll g : adj[x])
    {
        if (g == par) continue;
        dfs(g, x);
        distChild[x] = max(distChild[x], distChild[g] + 1);
    }
}
void dfs(ll x, ll par, ll dist, ll maxx)
{
    distPar[x] = maxx;
    ll first = -1, second = -1;
    for (ll g : adj[x])
    {
        if (g == par) continue;
        if (first == -1 || distChild[first] < distChild[g])
        {
            second = first;
            first = g;
        }
        else
        {
            if (distChild[first] == distChild[g])
            {
                second = g;
            }
            else
            {
                if (second == -1 || distChild[second] < distChild[g])
                {
                    second = g;
                }
            }
        }
    }
    //    cout<<x<<" "<<first<<" "<<second<<"\n";
    for (ll g : adj[x])
    {
        if (g == par) continue;
        if (g == first)
        {
            if (second == -1)
            {
                dfs(g, x, dist + 1, max(dist, maxx) + 1);
            }
            else
            {
                dfs(g, x, dist + 1, max({ dist + 1, maxx + 1,distChild[second] + 2 }));
            }
        }
        else
        {
            dfs(g, x, dist + 1, max({ dist + 1, maxx + 1,distChild[first] + 2 }));
        }
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
    dfs(1, -1, 0, 0);
    loop_up(i, 1, numNode)
    {
        //        cout<<distChild[i]<<" "<<distPar[i]<<"\n";
        cout << max(distChild[i], distPar[i]) << " ";
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
