/*
    Code by: KoKoDuDu
    Created: 2025.10.28 08:30:50
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
  string s;
  cin >> s;

  int n = s.size();
  vector<set<int>> a(26);

  if (n == 1) {
    cout << "YES\n";
    for (int i = 0; i < 26; ++i) cout << (char)(i + 'a');
    cout << '\n';
    return;
  }

  auto cv = [&](char c) -> int { return c - 'a'; };

  a[cv(s[0])].insert(cv(s[1]));
  a[cv(s[n - 1])].insert(cv(s[n - 2]));
  for (int i = 1; i < n - 1; ++i) {
    a[cv(s[i])].insert(cv(s[i + 1]));
    a[cv(s[i])].insert(cv(s[i - 1]));
  }

  vector<vector<int>> adj(26, vector<int>());
  vector<int> vst(26);

  int pos = -1;
  for (int i = 0; i < a.size(); ++i) {
    auto st = a[i];
    if (st.size() == 0) continue;
    if (st.size() > 2) return void(cout << "NO\n");
    if (st.size() == 1) pos = i;

    for (auto& c : st) adj[i].push_back(c);
  }

  if (pos == -1) return void(cout << "NO\n");

  cout << "YES\n";

  auto dfs = [&](auto&& dfs, int x, int p) -> void {
    vst[x] = 1;
    cout << (char)(x + 'a');
    for (auto& u : adj[x]) {
      if (u == p) continue;
      dfs(dfs, u, x);
    }
  };

  dfs(dfs, pos, -1);
  for (int i = 0; i < 26; ++i) {
    if (vst[i]) continue;
    dfs(dfs, i, -1);
  }
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