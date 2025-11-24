/*
 Code by: KoKoDuDu
 Created: 2025.11.21 14:06:09
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

// #ifdef ONLINE_JUDGE
// #define dbg(...)
// #else
// #include "debug.h"
// #endif

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

struct Segment_Tree_Max {
  vector<int> st;
  int n;

  Segment_Tree_Max() {}

  Segment_Tree_Max(int n) {
    this->n = n;
    st.assign(4 * n + 37, 0);
  }

  void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
      st[id] += val;
      return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid) {
      update(id * 2, l, mid, pos, val);
    } else {
      update(id * 2 + 1, mid + 1, r, pos, val);
    }

    st[id] = st[id * 2] + st[id * 2 + 1];
  }

  int get_sum(int id, int l, int r, int u, int v) {
    if (l > v || r < u || u > v) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    int s1 = get_sum(id * 2, l, mid, u, v);
    int s2 = get_sum(id * 2 + 1, mid + 1, r, u, v);
    return s1 + s2;
  }
};

void compress(vector<int>& a) {
  vector<int> b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());

  map<int, int> cnv;
  for (int i = 0; i < b.size(); ++i) cnv[b[i]] = i + 1;
  for (auto& x : a) x = cnv[x];
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto& x : a) cin >> x;

  compress(a);

  int lim = *max_element(a.begin(), a.end());
  Segment_Tree_Max pf_tree(lim), sf_tree(lim);

  int ans = 0;
  int l = 0, r = n, inv = 0;

  pf_tree.update(1, 1, lim, a[l], 1);
  while (l < r && inv <= k) {
    --r;
    sf_tree.update(1, 1, lim, a[r], 1);
    int pf_add = pf_tree.get_sum(1, 1, lim, a[r] + 1, lim);
    int sf_add = sf_tree.get_sum(1, 1, lim, 1, a[r] - 1);
    inv += pf_add + sf_add;
  }

  if (l == r) return void(cout << n * (n - 1) / 2 << '\n');
  ans += n - r - 1;

  for (int l = 1; l < n - 1; ++l) {
    pf_tree.update(1, 1, lim, a[l], 1);
    int pf_add = pf_tree.get_sum(1, 1, lim, a[l] + 1, lim);
    int sf_add = sf_tree.get_sum(1, 1, lim, 1, a[l] - 1);
    inv += pf_add + sf_add;

    while (r < n && inv > k) {
      sf_tree.update(1, 1, lim, a[r], -1);
      int pf_minus = pf_tree.get_sum(1, 1, lim, a[r] + 1, lim);
      int sf_minus = sf_tree.get_sum(1, 1, lim, 1, a[r] - 1);
      inv -= pf_minus + sf_minus;
      r++;
    }

    ans += n - r;
  }

  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
