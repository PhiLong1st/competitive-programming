/*
    Code by: KoKoDuDu
    Created: 2025.11.07 15:01:29
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
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

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
  int n, k;
  cin >> n >> k;

  vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  a[n + 1] = kMaxInf;

  Combinatorics comb(k);
  vector<vector<vector<int>>> f(n + 2,
                                vector<vector<int>>(k + 1, vector<int>(k + 1)));

  for (int i = 0; i <= k; ++i) f[1][i][0] = comb.get_nCk(k, i);

  for (int i = 1; i <= n; ++i) {
    for (int open = 0; open <= k; ++open) {
      for (int close = 0; close <= k; ++close) {
        if (f[i][open][close] == 0) continue;
        for (int new_close = 0; new_close <= open; ++new_close) {
          for (int new_open = 0; new_open <= k - open - close; ++new_open) {
            int nxt_open = open - new_close + new_open;
            int nxt_close = close + new_close;

            int cur_value = a[i] + open;
            int nxt_value = a[i + 1] + nxt_open;
            if (nxt_value <= cur_value) continue;

            int open_ways = comb.get_nCk(k - open - close, new_open);
            int close_ways = comb.get_nCk(open, new_close);
            int ways = open_ways * close_ways % kMod;

            f[i + 1][nxt_open][nxt_close] += f[i][open][close] * ways % kMod;
            f[i + 1][nxt_open][nxt_close] %= kMod;
          }
        }
      }
    }
  }

  cout << f[n + 1][0][k] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}