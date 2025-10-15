/*
    Code by: KoKoDuDu
    Created: 2025.10.15 23:42:16
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxN = 1e5 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

static inline int cdiv(int a, int b) {
  return a >= 0 ? (a + b - 1) / b : a / b;
}

static inline int fdiv(int a, int b) {
  return a <= 0 ? (a - b + 1) / b : a / b;
}

static inline void add_mod(int& a, int b) {
  a = a + b;
  if (a >= kMod) a -= kMod;
}

static inline int mul_mod(int a, int b) {
  a = a * b % kMod;
  return a;
}

int n, m;

int mod_exp(int n, int x, int MOD) {
  int res = 1;
  while (x > 0) {
    if (x & 1) {
      res = (res * n) % MOD;
    }
    n = (n * n) % MOD;
    x >>= 1;
  }
  return res;
}

int inv(int a) { return a <= 1 ? a : kMod - (kMod / a) * inv(kMod % a) % kMod; }

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int test_case = 1;
  cin >> test_case;
  while (test_case--) {
    cin >> n >> m;
    if (n > m) {
      cout << 0 << '\n';
      continue;
    }

    if (n == 1) {
      cout << m << '\n';
      continue;
    }

    if (n == 2) {
      int t = m - n + 1;
      int ans = 1;
      add_mod(ans, mod_exp(t, n, kMod));
      cout << ans << '\n';
      continue;
    }

    int ans = m - n + 2;
    int t = m - n + 1;
    int u = 2;

    if (t != 1) {
      int res = (mod_exp(t, n - 1, kMod) - mod_exp(t, u, kMod) + kMod) % kMod;
      res = res * inv(t - 1) % kMod;
      add_mod(ans, res);
    } else {
      add_mod(ans, n - 3);
    }

    add_mod(ans, mod_exp(m - n + 1, n, kMod));
    cout << ans << '\n';
  }
  return 0;
}