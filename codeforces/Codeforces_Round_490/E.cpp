/*
 Code by: KoKoDuDu
 Created: 2026.10.22 17:36:11
*/

#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second

using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

void add_mod(int& a, int b) { a = a + b >= kMod ? a + b - kMod : a + b; }

void minus_mod(int& a, int b) { a = (a - b + kMod) % kMod; }

void mul_mod(int& a, int b) { a = a * b % kMod; }

void maximize(int& x, int y) { x = max(x, y); }

void minimize(int& x, int y) { x = min(x, y); }

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res;
}

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

void solve() {
  int n, m, s;
  cin >> n >> m >> s;

  vector<vector<int>> adj(n + 1, vector<int>());
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  vector<int> topo;
  vector<int> seen(n + 1);

  auto dfs1 = [&](auto&& dfs, int u) -> void {
    seen[u] = 1;

    for (auto& v : adj[u]) {
      if (seen[v]) continue;
      dfs(dfs, v);
    }

    topo.push_back(u);
  };

  for (int i = 1; i <= n; ++i) {
    if (seen[i]) continue;
    dfs1(dfs1, i);
  }

  vector<int> vst(n + 1);
  auto dfs2 = [&](auto&& dfs, int u) -> void {
    vst[u] = 1;
    for (auto& v : adj[u]) {
      if (vst[v]) continue;
      dfs(dfs, v);
    }
  };

  dfs2(dfs2, s);
  int res = 0;
  for (int i = topo.size() - 1; i >= 0; --i) {
    int u = topo[i];
    if (vst[u]) continue;
    dfs2(dfs2, u);
    res++;
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
