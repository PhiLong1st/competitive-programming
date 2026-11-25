/*
 Code by: KoKoDuDu
 Created: 2025.12.08 15:52:40
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
  vector<int> tree, lazy;
  int n;

  Segment_Tree(int size) {
    n = size;
    tree.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
  }

  void push(int v, int tl, int tr) {
    int val = lazy[v];
    lazy[v] = 0;

    if (val == 0) return;

    tree[v] += val;
    if (tl == tr) return;

    lazy[2 * v] += val;
    lazy[2 * v + 1] += val;
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
    if (l > r) return kMaxInf;
    push(v, tl, tr);

    if (l == tl && r == tr) return tree[v];

    int tm = (tl + tr) / 2;
    int s1 = query(2 * v, tl, tm, l, min(r, tm));
    int s2 = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return min(s1, s2);
  }

  void update(int l, int r, int val) { update(1, 1, n, l, r, val); }

  int query(int l, int r) { return query(1, 1, n, l, r); }
};

void solve() {
  int n, k;
  cin >> n >> k;

  vector<pii> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a.begin() + 1, a.end(), greater<>());
  vector<int> ans(n + 1);

  Segment_Tree tree(n);
  for (int i = 1; i <= n; ++i) {
    vector<pii> storage;
    storage.emplace_back(a[i]);
    while (i < n && a[i].first == a[i + 1].first) {
      storage.emplace_back(a[i + 1]);
      ++i;
    }
    for (auto& [x, pos] : storage) {
      int l = max(1ll, pos - k + 1), r = min(pos, n - k + 1);
      ans[pos] = tree.query(l, r);
    }
    for (auto& [x, pos] : storage) {
      int l = max(1ll, pos - k + 1), r = min(pos, n - k + 1);
      tree.update(l, r, 1);
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] + 1 << ' ';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
