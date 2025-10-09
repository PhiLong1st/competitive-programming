/*
    Code by: KoKoDuDu
    Created: 2025.10.08 13:09:40
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

// #ifdef ONLINE_JUDGE
// #define dbg(...)
// #else
// #include "templates\debug.h"
// #endif

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
  int n, m;
  cin >> n >> m;

  Combinatorics comb(200000, kMod);

  vector<int> a(n), poly_state(101);

  for (auto& c : a) cin >> c;

  vector<vector<int>> save_start(n, vector<int>(101));
  vector<vector<pii>> save_end(n + 1);

  while (m--) {
    int l, r, k;
    cin >> l >> r >> k;
    save_start[l - 1][k]++;
    save_end[r].push_back({k, l - 1});
  }

  for (int i = 0; i < n; ++i) {
    vector<int> temp = save_start[i];

    int suf = 0;
    for (int j = 100; j >= 0; --j) {
      suf = (suf + poly_state[j]) % kMod;
      temp[j] = (temp[j] + suf) % kMod;
    }

    poly_state = temp;

    for (auto [k, l] : save_end[i]) {
      for (int j = 0; j <= k; j++) {
        int minus = comb.get_nCk(i - 1 - l + k - j, k - j);
        poly_state[j] = (poly_state[j] - minus + kMod) % kMod;
      }
    }

    for (int j = 100; j >= 0; --j) {
      a[i] = (a[i] + poly_state[j]) % kMod;
    }

    cout << a[i] << ((i == n - 1) ? "\n" : " ");
  }
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