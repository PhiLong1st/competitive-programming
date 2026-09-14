/*
 Code by: Algorillas
 Created: 2026.09.05 16:21:12
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  int a, b;
  cin >> a >> b;
  vector<int> vst_a(n + 1), vst_b(n + 1);

  auto bfs = [&](int start, vector<int>& vst) -> void {
    queue<int> q;
    q.push(start);
    vst[start] = 1;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();

      for (auto v : adj[u]) {
        if (!vst[v]) {
          q.push(v);
          vst[v] = 1;
        }
      }
    }
  };

  bfs(a, vst_a);
  bfs(b, vst_b);
  for (int i = 1; i <= n; ++i) {
    if (vst_a[i] && vst_b[i]) return void(cout << "yes\n" << i << '\n');
  }
  cout << "no\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}