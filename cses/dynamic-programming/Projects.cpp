#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN = 2e5 + 0307;
ll st[4 * maxN];
struct haha
{
    ll fi, se, th;
} a[maxN];
bool cmp(haha a, haha b)
{
    return a.se < b.se;
}
void update(ll id, ll l, ll r, ll pos, ll val)
{
    if (l == r)
    {
        st[id] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (pos <= mid)
    {
        update(id * 2, l, mid, pos, val);
    }
    else
    {
        update(id * 2 + 1, mid + 1, r, pos, val);
    }
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}
ll getMax(ll id, ll l, ll r, ll u, ll v)
{
    if (l > v || r<u || l>r)
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se >> a[i].th;
    }
    sort(a + 1, a + n + 1, cmp);
    for (ll i = 1; i <= n; i++)
    {
        ll l = 1;
        ll r = i;
        ll vt = -1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (a[i].fi > a[mid].se)
            {
                vt = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        ll x = getMax(1, 1, n, 1, vt);
        update(1, 1, n, i, a[i].th + x);
    }
    cout << getMax(1, 1, n, 1, n);
}