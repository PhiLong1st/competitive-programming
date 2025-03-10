#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 2e5 + 0307;
ll st[4 * maxN], a[maxN], dp[maxN];
set<ll>save;
map<ll, ll>num;
ll getMax(ll id, ll l, ll r, ll u, ll v)
{
    if (l > v || r<u || u>v)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    ll mid = (l + r) / 2;
    ll s1 = getMax(id * 2, l, mid, u, v);
    ll s2 = getMax(id * 2 + 1, mid + 1, r, u, v);
    return max(s1, s2);
}
void update(ll id, ll l, ll r, ll pos, ll val)
{
    if (l == r)
    {
        st[id] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (pos > mid)
    {
        update(id * 2 + 1, mid + 1, r, pos, val);
    }
    else
    {
        update(id * 2, l, mid, pos, val);
    }
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        save.insert(a[i]);
    }
    ll dem = 0;
    for (ll u : save)
    {
        dem++;
        num[u] = dem;
    }
    for (ll i = 1; i <= n; i++)
    {
        a[i] = num[a[i]];
    }
    for (ll i = 1; i <= n; i++)
    {
        ll maxx = getMax(1, 1, dem, 1, a[i] - 1);
        update(1, 1, dem, a[i], maxx + 1);
    }
    cout << getMax(1, 1, dem, 1, dem);
}