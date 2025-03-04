/*
    Code by: KoKoDuDu

*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;


struct Segment_Tree
{
    vector<int> st;
    int n;
    Segment_Tree()
    {
    }
    Segment_Tree(int n)
    {
        this->n = n;
        st.assign(4 * n + 37, 0);
    }
    void update(int id, int l, int r, int pos, int val)
    {
        int mid = (l + r) >> 1;
        if (l == r)
        {
            st[id] = val;
            return;
        }
        if (pos <= mid)
        {
            update(id * 2, l, mid, pos, val);
        }
        else
        {
            update(id * 2 + 1, mid + 1, r, pos, val);
        }
        st[id] = st[id * 2] + st[id * 2 + 1];
    }
    int getSum(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
        {
            return 0;
        }
        if (u <= l && r <= v)
        {
            return st[id];
        }
        int mid = (l + r) >> 1;
        int s1 = getSum(id * 2, l, mid, u, v);
        int s2 = getSum(id * 2 + 1, mid + 1, r, u, v);
        return s1 + s2;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.end(), greater<>());
    int ans = 0;
    Segment_Tree tree(n);
    for (int i = 1; i <= n; ++i) {

        int l = 1, r = i, left = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = tree.getSum(1, 1, n, mid, a[i].second);
            if (val != 0) {
                l = mid + 1;
                left = val;
            }
            else {
                r = mid - 1;
            }
        }

        l = i, r = n;
        int right = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = tree.getSum(1, 1, n, a[i].second, mid);
            if (val != 0) {
                r = mid - 1;
                right = val;
            }
            else {
                l = mid + 1;
            }
        }

        ans += left != a[i].first && left != 0;
        ans += right != a[i].first && right != 0;

        tree.update(1, 1, n, a[i].second, a[i].first);
        // cout << a[i].first << ' ' << a[i].second << ' ' << ans << '\n';
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}