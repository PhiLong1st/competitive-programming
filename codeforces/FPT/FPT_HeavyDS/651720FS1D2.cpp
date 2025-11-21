/*
 Code by: KoKoDuDu
 Created: 2025.11.19 10:48:21
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
const int kMaxN = 1e6 + 0307;
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

int a[kMaxN];
int max_st[4 * kMaxN];
int st[4 * kMaxN];
int n, q;

void update_max_st(int id, int l, int r, int pos, int val) {
  int mid = (l + r) >> 1;

  if (l == r) {
    max_st[id] = val;
    return;
  }

  if (pos <= mid) {
    update_max_st(id * 2, l, mid, pos, val);
  } else {
    update_max_st(id * 2 + 1, mid + 1, r, pos, val);
  }

  int p1 = max_st[id * 2], p2 = max_st[id * 2 + 1];
  max_st[id] = a[p1] < a[p2] ? p2 : p1;
}

int get_max_st(int id, int l, int r, int u, int v) {
  if (l > v || r < u) return 0;
  if (u <= l && r <= v) return max_st[id];

  int mid = (l + r) >> 1;
  int p1 = get_max_st(id * 2, l, mid, u, v);
  int p2 = get_max_st(id * 2 + 1, mid + 1, r, u, v);

  if (p1 == 0) return p2;
  if (p2 == 0) return p1;
  return a[p1] < a[p2] ? p2 : p1;
}

void init(int id, int l, int r) {
  if (l == r) {
    st[id] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  init(id * 2, l, mid);
  init(id * 2 + 1, mid + 1, r);
}

void build(int id, int l, int r) {
  if (l >= r) return;
  int mid = get_max_st(1, 1, n, l, r);
  build(id * 2, l, mid - 1);
  build(id * 2 + 1, mid + 1, r);
  st[id] = st[id * 2] + st[id * 2 + 1] + 1;
}

int get(int id, int l, int r, int u, int v) {
  if (l < 1 || l > r || l > v || r < u) return 0;
  if (u == l && r == v) return st[id];

  int mid = get_max_st(1, 1, n, l, r);
  int p1 = get(id * 2, l, mid - 1, u, v);
  int p2 = get(id * 2 + 1, mid + 1, r, u, v);
  return p1 + p2 + 1;
}

int calc(int l, int r) {
  if (l == r) return 1;
  if (l < 1 || l > r) return 0;
  int mid = get_max_st(1, 1, n, l, r);
  int p1 = calc(l, mid - 1) + mid - l;
  int p2 = calc(mid + 1, r) + r - mid;
  return p1 + p2 + 1;
}

void solve() {
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    update_max_st(1, 1, n, i, i);
  }

  vector<int> l(q), r(q);
  for (auto& x : l) cin >> x;
  for (auto& x : r) cin >> x;

  for (int i = 0; i < q; ++i) {
    cout << l[i] << ' ' << r[i] << ' ' << calc(l[i], r[i]) << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
