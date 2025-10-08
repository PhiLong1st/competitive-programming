/*
    Code by: KoKoDuDu
    Created: 2025.10.08 15:58:39
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxN = 2e5 + 0307;
const int kMaxK = 17;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

int cnt_mod[kMaxK][kMaxK];
long long dp[kMaxK][kMaxK][kMaxK];

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

struct Combinatorics {
  int n, MOD;
  vector<int> fact, inv, fact_inv;

  Combinatorics(int n, int MOD)
      : n(n), MOD(MOD), fact(n + 1), inv(n + 1), fact_inv(n + 1) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
  }

  int get_nCk(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * fact_inv[k] % MOD * fact_inv[n - k] % MOD;
  }

  int get_inv_fact(int i) { return fact_inv[i]; }
  int get_fact(int i) { return fact[i]; }
  int get_inv(int i) { return inv[i]; }
};

void solve() {
  int n, k;
  cin >> n >> k;

  Combinatorics comb(kMaxN, kMod);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    cnt_mod[x % k][y % k]++;
  }

  dp[0][0][0] = 1;
  for (int gx = 0; gx < k; ++gx) {
    for (int gy = 0; gy < k; ++gy) {
      int count = cnt_mod[gx][gy];
      if (count == 0) continue;

      for (int sz = k; sz >= 0; --sz) {
        for (int rx = 0; rx < k; ++rx) {
          for (int ry = 0; ry < k; ++ry) {
            if (dp[sz][rx][ry] == 0) continue;

            for (int c = 1; c <= count; ++c) {
              if (sz + c > k) break;

              int new_rx = (rx + c * gx) % k, new_ry = (ry + c * gy) % k;
              int new_val = dp[sz][rx][ry] * comb.get_nCk(count, c);

              dp[sz + c][new_rx][new_ry] += new_val;
              dp[sz + c][new_rx][new_ry] %= kMod;
            }
          }
        }
      }
    }
  }

  cout << dp[k][0][0];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}