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
ll d[maxN];
ll cha[maxN][22];
void DFS(ll u, ll par)
{
    for (ll g : adj[u])
    {
        if (g != par)
        {
            d[g] = d[u] + 1;
            cha[g][0] = u;
            DFS(g, u);
        }
    }
}
ll findPar(ll u, ll k)
{
    for (ll i = 20; i >= 0; i--)
    {
        if ((d[u] - d[cha[u][i]]) <= k)
        {
            u = cha[u][i];
            k -= (1 << i);
            if (k == 0)
            {
                return u;
            }
        }
    }
    return -1;
}
void solve()
{
    ll numNode, q;
    cin >> numNode >> q;
    loop_up(i, 2, numNode)
    {
        ll x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    DFS(1, -1);
    for (ll j = 1; j <= 20; j++)
    {
        for (ll i = 1; i <= numNode; i++)
        {
            cha[i][j] = cha[cha[i][j - 1]][j - 1];
        }
    }
    d[0] = -1;
    while (q--)
    {
        ll u, k;
        cin >> u >> k;
        cout << findPar(u, k) << "\n";
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
