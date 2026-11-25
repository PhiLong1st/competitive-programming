/*
 Code by: KoKoDuDu
 Created: 2026.10.10 01:26:16
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
const int kMod = 998244353;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

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

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<vector<int>>> f(n + 1,
                                vector<vector<int>>(n + 1, vector<int>(n + 1)));

  f[0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int maxx = 0;
    vector<int> save;
    unordered_map<int, int> cnt;

    for (int j = i; j >= 1; --j) {
      cnt[a[j]]++;

      if (maxx <= cnt[a[j]]) {
        if (maxx < cnt[a[j]]) save.clear();
        save.push_back(a[j]);
        maxx = cnt[a[j]];
      }

      for (int& x : save) {
        for (int sz = 1; sz <= i; ++sz) {
          bool isOk = false;
          for (int y = 0; y <= n; ++y) isOk |= f[j - 1][sz - 1][y] != 0;
          f[i][sz][x] += isOk;
        }
      }
    }

    for (int sz = 1; sz <= i; ++sz)
      for (int y = 0; y <= n; ++y) dbg(i, sz, y, f[i][sz][y]);
  }

  int res = 0;
  for (int sz = 1; sz <= n; ++sz)
    for (int y = 0; y <= n; ++y) res += f[n][sz][y];
  cout << res << '\n';
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
