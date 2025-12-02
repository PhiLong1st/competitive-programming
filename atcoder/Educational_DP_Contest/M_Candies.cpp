/*
 Code by: KoKoDuDu
 Created: 2025.12.01 16:15:55
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

void add_mod(int& a, int b) {
  a += b;
  if (a >= kMod) a -= kMod;
  if (a < 0) a += kMod;
}

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

  void add(int idx, int val) {
    if (val < 0) val = (val % kMod + kMod) % kMod;
    for (; idx <= n; idx += idx & -idx) {
      bit[idx] += val;
      if (bit[idx] >= kMod) bit[idx] -= kMod;
    }
  }

  int sum(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) {
      res += bit[idx];
      if (res >= kMod) res -= kMod;
    }
    return res;
  }

  int range_sum(int l, int r) {
    if (l > r) return 0;
    int res = sum(r) - sum(l - 1);
    if (res < 0) res += kMod;
    return res;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  ++k;

  Fenwick fw(k);
  vector<int> dp(k + 1, 0);

  dp[1] = 1;
  fw.add(1, 1);

  for (int i = 1; i <= n; ++i) {
    for (int j = k; j >= 1; --j) {
      int l = max(1LL, j - a[i]), r = j;
      int sum = fw.range_sum(l, r);

      int temp = dp[j];
      dp[j] = sum;

      int dt = sum - temp;
      if (dt < 0) dt += kMod;

      fw.add(j, dt);
    }
  }

  cout << dp[k] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
