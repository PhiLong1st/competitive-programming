/*
    Code by: KoKoDuDu
    Created: 2025.10.17 10:57:27
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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

int fpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res % kMod;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> forb;
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;

    int mask = 0;
    for (int j = 0; j < k; ++j) {
      char c;
      cin >> c;
      mask |= (1 << (c - 'a'));
    }

    forb.push_back(mask);
  }

  vector<int> cnt(8);
  for (int mask = 0; mask < (1 << 7); ++mask) {
    bool is_ok = true;
    for (auto f : forb) {
      if ((mask & f) == f) {
        is_ok = false;
        break;
      }
    }
    if (is_ok) cnt[__builtin_popcount(mask)]++;
  }

  int C[8][8];
  for (int t = 0; t <= 7; ++t) {
    C[t][0] = C[t][t] = 1;
    for (int i = 1; i < t; ++i)
      C[t][i] = (C[t - 1][i - 1] + C[t - 1][i]) % kMod;
  }

  int ans = 0;
  for (int t = 1; t <= 7; ++t) {
    if (cnt[t] == 0) continue;

    int onto = 0;
    for (int i = 0; i <= t; ++i) {
      int term = mul_mod(C[t][i], fpow(t - i, n));
      if (i & 1)
        add_mod(onto, kMod - term);
      else
        add_mod(onto, term);
    }

    add_mod(ans, mul_mod(cnt[t], onto));
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