/*
    Code by: KoKoDuDu
    Created: 2025.10.09 10:41:27
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

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
  string s;
  cin >> s;

  int n = s.size();
  vector<int> suf(n + 1);

  Combinatorics comb(n + 1, kMod);

  for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + (s[i] == ')');

  int open_cnt = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    open_cnt += s[i] == '(';
    if (s[i] == '(') {
      ans = (ans + comb.get_nCk(suf[i] + open_cnt - 1, open_cnt)) % kMod;
    }
  }

  cout << ans;
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