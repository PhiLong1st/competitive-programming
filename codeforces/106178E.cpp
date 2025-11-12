/*
   Code by: linvg
   Created: 2025.11.12 20:15:37
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 1e16;
const int MOD = 1e9 + 7;
const int N = 3e5 + 7;
int compress[N];

struct SegmentTree {
  vector<int> tree, lazy;
  int n;

  SegmentTree(int size) {
    n = size;
    tree.assign(4 * n, INF);
    lazy.assign(4 * n, 0);
  }

  void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
      tree[v] += lazy[v];
      if (tl != tr) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
      }
      lazy[v] = 0;
    }
  }

  void update(int v, int tl, int tr, int l, int r, int val) {
    push(v, tl, tr);
    if (l > r) return;
    if (l == tl && r == tr) {
      lazy[v] += val;
      push(v, tl, tr);
      return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    push(2 * v, tl, tm);
    push(2 * v + 1, tm + 1, tr);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
  }

  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 2 * INF;
    push(v, tl, tr);
    if (l == tl && r == tr) return tree[v];
    int tm = (tl + tr) / 2;
    return min(query(2 * v, tl, tm, l, min(r, tm)),
               query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
  }

  void update(int l, int r, int val) { update(1, 1, n, l, r, val); }

  int query(int l, int r) { return query(1, 1, n, l, r); }
};

int fw[N + 7];

void add(int i, int v) {
  for (; i <= N; i += i & -i) fw[i] += v;
}

int get(int i) {
  int res = 0;
  for (; i > 0; i -= i & -i) res += fw[i];
  return res;
}

void solve() {
  int n;
  cin >> n;
  unordered_map<int, int> freq;
  freq.reserve(1000);

  vector<int> a;
  vector<int> vals;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
    vals.push_back(abs(x));
  }

  vals.push_back(0);
  sort(all(vals));
  vals.erase(unique(all(vals)), vals.end());
  for (int i = 0; i < sz(vals); ++i) {
    compress[i] = vals[i];
  }

  SegmentTree st(N + 1);

  for (int i = 0; i < n; ++i) {
    int x = a[i];

    if (x > 0) {
      x = lower_bound(all(vals), x) - vals.begin();

      add(x, 1);
      st.update(1, x - 1, 1);
      freq[x]++;

      if (freq[x] == 1) {
        int cur = st.query(x, x);
        st.update(x, x, (get(N) - get(x) + vals[x]) - cur);
      }

      cout << min(st.query(1, N), get(N)) << ' ';

    } else {
      x = -x;
      x = lower_bound(all(vals), x) - vals.begin();
      freq[x]--;
      add(x, -1);

      st.update(1, x - 1, -1);
      if (freq[x] == 0) {
        st.update(x, x, INF);
      } else {
      }

      cout << min(st.query(1, N), get(N)) << ' ';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}