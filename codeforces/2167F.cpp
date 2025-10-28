/*
    Code by: KoKoDuDu
    Created: 2025.10.28 22:27:49
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
  int n, k;
  cin >> n >> k;

  Combinatorics comb(n);

  vector<vector<int>> adj(n + 1, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> num_child(n + 1, 1);

  auto dfs = [&](auto&& dfs, int u, int p) -> void {
    for (auto& v : adj[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
      num_child[u] += num_child[v];
    }
  };

  int ways = 0;
  auto calc = [&](auto&& calc, int u, int p) -> void {
    ways += num_child[u] < k ? 0 : n - num_child[u];
    for (int v : adj[u]) {
      if (v == p) continue;
      ways += (n - num_child[v] < k) ? 0 : num_child[v];
      calc(calc, v, u);
    }
  };

  dfs(dfs, 1, -1);
  calc(calc, 1, -1);
  cout << ways + n << '\n';
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