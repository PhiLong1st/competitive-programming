/*
 Code by: KoKoDuDu
 Created: 2025.11.21 16:54:45
*/

#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second

using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

int add_mod(int a, int b) { return a + b >= kMod ? a + b - kMod : a + b; }

int minus_mod(int a, int b) { return (a - b + kMod) % kMod; }

int mul_mod(int a, int b) { return a * b % kMod; }

void maximize(int& x, int y) { x = max(x, y); }

void minimize(int& x, int y) { x = min(x, y); }

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res;
}

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

struct Query {
  int l, r, id;
};

struct Segment_Tree_Max {
  int n;
  vector<pii> lazy;

  Segment_Tree_Max(int n = 0) {
    this->n = n;
    lazy.assign(4 * n + 5, {0, 0});
  }

  void update(int v, int tl, int tr, int l, int r, pii f) {
    if (l > r) return;

    if (l <= tl && tr <= r) {
      lazy[v].fi += f.fi;
      lazy[v].se += f.se;
      return;
    }

    int tm = (tl + tr) >> 1;
    update(v << 1, tl, tm, l, min(r, tm), f);
    update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, f);
  }

  pii query(int v, int tl, int tr, int pos, pii val) {
    val.fi += lazy[v].fi;
    val.se += lazy[v].se;

    if (tl == tr) return val;

    int tm = (tl + tr) >> 1;
    if (pos <= tm)
      return query(v << 1, tl, tm, pos, val);
    else
      return query(v << 1 | 1, tm + 1, tr, pos, val);
  }

  void update(int l, int r, pii f) { update(1, 0, n - 1, l, r, f); }

  pii query(int pos) { return query(1, 0, n - 1, pos, {0, 0}); }
};

void solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n), ans(q);
  vector<Query> qr(q);
  for (auto& x : a) cin >> x;
  for (auto& [l, r, id] : qr) cin >> l;
  for (auto& [l, r, id] : qr) cin >> r;

  for (int i = 0; i < q; ++i) {
    qr[i].l--;
    qr[i].r--;
    qr[i].id = i;
  }

  for (auto& [l, r, id] : qr) ans[id] = r - l + 1;

  for (int t = 0; t < 2; ++t) {
    vector<int> st, lf(n, -1);
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
      if (!st.empty()) lf[i] = st.back();
      st.push_back(i);
    }

    sort(qr.begin(), qr.end(), [&](Query& x, Query& y) -> bool {
      if (x.r != y.r) return x.r < y.r;
      return x.l < y.l;
    });

    Segment_Tree_Max tree(n);
    int pos = 0;

    for (int i = 0; i < n; ++i) {
      tree.update(0, lf[i], {0, i - lf[i] - 1});
      tree.update(lf[i] + 1, i, {-1, i});

      while (pos < q && qr[pos].r == i) {
        pii val = tree.query(qr[pos].l);
        ans[qr[pos].id] += val.fi * qr[pos].l + val.se;
        ++pos;
      }
    }

    reverse(a.begin(), a.end());
    for (auto& [l, r, id] : qr) {
      l = n - 1 - l, r = n - 1 - r;
      swap(l, r);
    }
  }

  for (auto& x : ans) cout << x << ' ';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
