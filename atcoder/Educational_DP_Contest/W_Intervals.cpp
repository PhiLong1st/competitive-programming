/*
 Code by: KoKoDuDu
 Created: 2025.12.02 15:36:23
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
const int kMaxInf = 1e16;
const int kMinInf = -1e16;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

void add_mod(int& a, int b) { a = a + b >= kMod ? a + b - kMod : a + b; }

void minus_mod(int& a, int b) { a = (a - b + kMod) % kMod; }

void mul_mod(int& a, int b) { a = a * b % kMod; }

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

struct Segment_Tree {
  int n;
  vector<int> st, lazy;

  Segment_Tree(int n) {
    this->n = n;
    st.assign(4 * n + 37, kMinInf);
    lazy.assign(4 * n + 37, 0);
  }

  void apply(int v, int val) {
    st[v] += val;
    lazy[v] += val;
  }

  void push(int v) {
    if (lazy[v] == 0) return;

    apply(v << 1, lazy[v]);
    apply(v << 1 | 1, lazy[v]);
    lazy[v] = 0;
  }

  void range_add(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;

    if (l <= tl && tr <= r) {
      apply(v, val);
      return;
    }

    push(v);

    int tm = (tl + tr) >> 1;
    if (l <= tm) range_add(v << 1, tl, tm, l, min(r, tm), val);
    if (r > tm) range_add(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
    st[v] = max(st[v << 1], st[v << 1 | 1]);
  }

  int range_max(int v, int tl, int tr, int l, int r) {
    if (l > r) return kMinInf;

    if (l <= tl && tr <= r) return st[v];

    push(v);

    int tm = (tl + tr) >> 1;
    int res = kMinInf;

    if (l <= tm) res = max(res, range_max(v << 1, tl, tm, l, min(r, tm)));

    if (r > tm)
      res = max(res, range_max(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));

    return res;
  }

  void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      st[v] = val;
      lazy[v] = 0;
      return;
    }

    push(v);

    int tm = (tl + tr) >> 1;
    if (pos <= tm)
      update(v << 1, tl, tm, pos, val);
    else
      update(v << 1 | 1, tm + 1, tr, pos, val);

    st[v] = max(st[v << 1], st[v << 1 | 1]);
  }

  int range_max(int l, int r) { return range_max(1, 1, n, l, r); }

  void range_add(int l, int r, int val) { range_add(1, 1, n, l, r, val); }

  void set(int pos, int val) { update(1, 1, n, pos, val); }
};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> l(m + 1), r(m + 1), a(m + 1);
  for (int i = 1; i <= m; ++i) cin >> l[i] >> r[i] >> a[i];

  vector<vector<pii>> add(n + 1, vector<pii>()), remove(n + 2, vector<pii>());
  for (int i = 1; i <= m; ++i) {
    add[l[i]].emplace_back(l[i], a[i]);
    remove[r[i] + 1].emplace_back(l[i], a[i]);
  }

  Segment_Tree tree(n + 1);
  tree.set(1, 0);

  vector<int> dp(n + 1, kMinInf);
  dp[0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (auto& [idx, val] : add[i]) tree.range_add(1, idx, val);
    for (auto& [idx, val] : remove[i]) tree.range_add(1, idx, -val);
    dp[i] = tree.range_max(1, i);
    tree.set(i + 1, dp[i]);
  }

  cout << *max_element(dp.begin(), dp.end());
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
