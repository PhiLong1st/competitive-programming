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
ll dp[maxN][2];
void dfs(ll x, ll par)
{
    ll dem = 0;
    for (ll child : adj[x])
    {
        if (child != par)
        {
            dem++;
        }
    }
    if (dem == 0)
    {
        dp[x][1] = 0;
        dp[x][0] = 0;
        return;
    }
    for (ll child : adj[x])
    {
        if (child != par)
        {
            dfs(child, x);
        }
    }
    for (ll child : adj[x])
    {
        if (child != par)
        {
            dp[x][0] += max(dp[child][0], dp[child][1]);
        }
    }
    ll sum = 0;
    for (ll child : adj[x])
    {
        if (child != par)
            sum += max(dp[child][0], dp[child][1]);
    }
    for (ll child : adj[x])
    {
        if (child != par)
            dp[x][1] = max(dp[x][1], sum - max(dp[child][0], dp[child][1]) + 1 + dp[child][0]);
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
    ll kq = 0, sum = 0;

    for (ll child : adj[1])
    {
        sum += (dp[child][1]);
    }
    for (ll child : adj[1])
    {
        kq = max(kq, sum - dp[child][1] + 1 + dp[child][0]);
    }
    cout << kq;
}
int main()
{
    fastio
        ll numTest = 1;
    while (numTest--)
    {
        solve();
    }
}
