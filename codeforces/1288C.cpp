/*
    Code by: KoKoDuDu
    Created: 2025.10.27 21:53:07
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

struct Combinatorics {
  int n;
  vector<int> fact, inv, fact_inv;

  Combinatorics(int n) : n(n), fact(n + 1), inv(n + 1), fact_inv(n + 1) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      inv[i] = kMod - (kMod / i) * inv[kMod % i] % kMod;
    }

    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[i] = fact[i - 1] * i % kMod;
      fact_inv[i] = fact_inv[i - 1] * inv[i] % kMod;
    }
  }

  int get_nCk(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * fact_inv[k] % kMod * fact_inv[n - k] % kMod;
  }

  int get_inv_fact(int i) { return fact_inv[i]; }

  int get_fact(int i) { return fact[i]; }

  int get_inv(int i) { return inv[i]; }
};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<vector<int>>> dp(
      m + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[1][i][j] = 1;
    }
  }

  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      int sum = (dp[1][x - 1][y] + dp[1][x][y - 1]) % kMod;
      int minus = dp[1][x - 1][y - 1];
      dp[1][x][y] += (sum - minus + kMod) % kMod;
      dp[1][x][y] %= kMod;
    }
  }

  for (int sz = 2; sz <= m; ++sz) {
    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= x; ++y) {
        dp[sz][x][y] += (dp[sz - 1][x][n] - dp[sz - 1][x][y - 1] + kMod) % kMod;
        dp[sz][x][y] %= kMod;
      }
    }

    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= n; ++y) {
        int sum = (dp[sz][x - 1][y] + dp[sz][x][y - 1]) % kMod;
        int minus = dp[sz][x - 1][y - 1];
        dp[sz][x][y] += (sum - minus + kMod) % kMod;
        dp[sz][x][y] %= kMod;
      }
    }
  }

  cout << dp[m][n][n] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}