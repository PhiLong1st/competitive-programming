/*
 Code by: KoKoDuDu
 Created: 2025.12.01 18:54:16
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

struct Fenwick {
  int n;
  vector<int> bit;

  Fenwick() {}

  Fenwick(int _n) {
    n = _n;
    bit.assign(n + 1, 0);
  }

  void update(int u, int v) {
    int idx = u;
    while (idx <= n) {
      bit[idx] = max(bit[idx], v);
      idx += (idx & (-idx));
    }
  }

  int get_max(int p) {
    int idx = p, ans = 0;
    while (idx > 0) {
      ans = max(ans, bit[idx]);
      idx -= (idx & (-idx));
    }
    return ans;
  }
};

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), q(n);
  for (int& x : a) cin >> x;
  for (int& x : q) cin >> x;

  Fenwick tree(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cost = tree.get_max(a[i]);
    int val = cost + q[i];
    ans = max(ans, val);
    tree.update(a[i], val);
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
