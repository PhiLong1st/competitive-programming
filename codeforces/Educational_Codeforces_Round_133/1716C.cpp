/*
 Code by: KoKoDuDu
 Created: 2025.11.25 14:52:44
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
const int kMaxBit = 20;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

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

struct Sparse_table {
  vector<vector<int>> spt;
  vector<int> arr;

  Sparse_table(vector<int> arr) {
    this->arr = arr;
    spt.assign(kMaxBit, vector<int>(arr.size()));
    build();
  }

  void build() {
    for (int i = 0; i < arr.size(); i++) spt[0][i] = arr[i] - i;

    for (int bit = 1; bit < kMaxBit; ++bit) {
      for (int i = 0; i + (1LL << bit) <= arr.size(); ++i) {
        int j = i + (1LL << (bit - 1));
        spt[bit][i] = max(spt[bit - 1][i], spt[bit - 1][j]);
      }
    }
  }

  int get_max(int l, int r) {
    if (l > r) return kMinInf;
    int len = r - l + 1;
    int lg = log2(len);
    return max(spt[lg][l], spt[lg][r - (1 << lg) + 1]);
  }
};

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> a(3, vector<int>(n + 1));
  vector<int> pf, sf, cost_pf(2 * n), cost_sf(2 * n);

  for (int i = 1; i <= 2; ++i)
    for (int j = 1; j <= n; ++j) cin >> a[i][j];

  for (int j = 1; j <= n; ++j) pf.push_back(a[1][j]), sf.push_back(a[1][j]);
  for (int j = n; j >= 1; --j) pf.push_back(a[2][j]), sf.push_back(a[2][j]);
  reverse(sf.begin(), sf.end());

  Sparse_table spt_pf(pf), spt_sf(sf);

  for (int i = 1; i < pf.size(); ++i)
    cost_pf[i] = cost_pf[i - 1] + max(0LL, pf[i] - cost_pf[i - 1]) + 1;

  for (int i = 1; i < sf.size(); ++i)
    cost_sf[i] = cost_sf[i - 1] + max(0LL, sf[i] - cost_sf[i - 1]) + 1;

  auto find = [&](int l, int r, int val, auto& spt) -> int {
    int pos = -1, nl = l, nr = r;
    while (nl <= nr) {
      int mid = (nl + nr) >> 1;
      int maxx = spt.get_max(l, mid);
      if (maxx >= val - l) {
        pos = mid;
        nr = mid - 1;
      } else {
        nl = mid + 1;
      }
    }
    return pos;
  };

  auto calc_pf = [&](int l, int r, int val) -> int {
    int pos = find(l, r, val, spt_pf);
    if (pos != -1) val = pf[pos] + 1;
    int res = (pos != -1) ? val + cost_pf[r] - cost_pf[pos] : val + r - l + 1;
    return res;
  };

  auto calc_sf = [&](int l, int r, int val) -> int {
    int pos = find(l, r, val, spt_sf);
    if (pos != -1) val = sf[pos] + 1;
    int res = (pos != -1) ? val + cost_sf[r] - cost_sf[pos] : val + r - l + 1;
    return res;
  };

  auto update = [&](int& cost, int val) -> void {
    cost = cost + max(0LL, val - cost) + 1;
  };

  int ans = cost_pf.back();
  int cost = 0, pf_sz = pf.size(), sf_sz = sf.size();
  for (int i = 1; i <= n; ++i) {
    if (i == n) {
      if (i % 2) {
        update(cost, a[1][i]), update(cost, a[2][i]);
      } else {
        update(cost, a[2][i]), update(cost, a[1][i]);
      }
      ans = min(ans, cost);
      break;
    }

    if (i % 2) {
      if (i != 1) {
        update(cost, a[1][i]);
        ans = min(ans, calc_pf(i, pf_sz - i, cost));
      }

      update(cost, a[2][i]);
      ans = min(ans, calc_sf(i, sf_sz - 1 - i, cost));
    } else {
      update(cost, a[2][i]);
      ans = min(ans, calc_sf(i, sf_sz - i, cost));

      update(cost, a[1][i]);
      ans = min(ans, calc_pf(i, pf_sz - 1 - i, cost));
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
