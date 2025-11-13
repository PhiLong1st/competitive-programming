/*
    Code by: KoKoDuDu
    Created: 2025.11.13 22:01:05
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

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1, vector<int>());
  for (int i = 1; i <= n - 1; ++i) {
    int x, y;
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<pii> ans;
  bool is_exist = false;

  int root = 1;
  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() > 1) continue;
    root = i;
  }

  auto dfs = [&](auto&& dfs, int u, int p, int type) -> void {
    int cnt_child = 0;
    for (auto& v : adj[u]) {
      if (v == p) continue;
      cnt_child++;
    }

    bool has_par = p != -1;
    bool has_one_child = cnt_child == 1;
    if (has_par && has_one_child && !is_exist) {
      is_exist = true;
      type = !type;
    }

    int next_type = !type;
    for (auto& v : adj[u]) {
      if (v == p) continue;
      if (type == 0) {
        ans.emplace_back(u, v);
      } else {
        ans.emplace_back(v, u);
      }
      dfs(dfs, v, u, next_type);
    }
  };

  // dbg(root);
  dfs(dfs, root, -1, 0);

  if (!is_exist) return void(cout << "NO\n");

  cout << "YES\n";
  for (auto& [x, y] : ans) cout << x << ' ' << y << '\n';
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