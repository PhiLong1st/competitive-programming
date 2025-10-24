/*
    Code by: KoKoDuDu
    Created: 2025.10.24 17:18:17
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int kMod = 1e9 + 7;
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

bool is_power2(int n) {
  if (n == 0) return false;
  while (n % 2 == 0) {
    n /= 2;
  }
  return n == 1;
}

void calc(int n, int k) {
  if (is_power2(n)) {
    for (int i = 1; i <= n; ++i) cout << k << ' ';
    return;
  }

  if (is_power2(n + 1)) {
    for (int i = 1; i <= n; ++i) {
      cout << ((i % 2) ? k : 0) << ' ';
    }
    return;
  }

  int bit = 31;
  for (int i = 31; i >= 0; --i) {
    if ((n & (1LL << i))) {
      bit = i;
      break;
    }
  }

  int m = n ^ (1LL << bit);
  calc(m, k);
  for (int i = 1; i <= n - 2 * m; ++i) cout << 0 << ' ';
  calc(m, k);
}

void solve() {
  int n, k;
  cin >> n >> k;

  calc(n, k);
  cout << '\n';
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
