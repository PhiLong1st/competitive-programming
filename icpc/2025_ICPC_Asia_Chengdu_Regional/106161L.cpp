/*
 Code by: Algorillas
 Created: 2026.09.23 20:31:29
*/

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<unordered_map<int, int>> color(n + 1);
  vector<int> zero(n + 1), cost(n + 1);
  vector<bool> res(n + 1);

  function<void(int, int)> dfs = [&](int u, int parent) {
    for (int v : adj[u]) {
      if (v == parent) continue;
      dfs(v, u);
      auto& color_u = color[u];
      auto& color_v = color[v];
      if (color_u.size() < color_v.size()) {
        swap(color_u, color_v);
        cost[u] = cost[v];
      }
      for (auto& [x, y] : color_v) {
        cost[u] -= abs(color[u][x]);
        color[u][x] += y;
        cost[u] += abs(color[u][x]);
      }
      zero[u] += zero[v];
    }
    if (a[u] == 0)
      zero[u]++;
    else {
      cost[u] -= abs(color[u][a[u]]);
      color[u][a[u]]++;
      cost[u] += abs(color[u][a[u]]);
    }
    if (b[u] == 0)
      zero[u]++;
    else {
      cost[u] -= abs(color[u][b[u]]);
      color[u][b[u]]--;
      cost[u] += abs(color[u][b[u]]);
    }

    int num_zero = zero[u];

    if (num_zero >= cost[u])
      res[u] = true;
    else
      res[u] = false;
  };
  dfs(1, -1);
  for (int u = 1; u <= n; u++) cout << (res[u] ? 1 : 0);
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}