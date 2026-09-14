/*
 Code by: Algorillas
 Created: 2026.09.14 20:03:45
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
  int n, queries;
  cin >> n >> queries;
  vector<vector<int>> adj(n + 1);
  vector<int> deg(n + 1, 0);
  while (queries-- > 0) {
    int l, r;
    cin >> l >> r;
    // cout << "! " << l << " " << r << "\n";

    if (r - l + 1 < 2) {
      int x;
      cin >> x;
      continue;
    }
    // cout << "! " << l << " " << r << "\n";
    int pre, cur;
    pre = cur = -1;
    for (int i = l; i <= r; i++) {
      cin >> cur;
      if (pre != -1) {
        adj[pre].push_back(cur);
        // cout << pre << " " << cur << "\n";
        deg[cur]++;
      }
      pre = cur;
    }
  }
  // cout << "\n";

  vector<int> vst(n + 1, 0);
  function<bool(int)> check_cycle = [&](int u) -> bool {
    vst[u] = 1;
    for (int v : adj[u]) {
      if (vst[v] == 2) continue;
      ;
      if (vst[v] == 1) return true;
      if (check_cycle(v)) return true;
    }
    vst[u] = 2;
    return false;
  };

  for (int u = 1; u <= n; u++) {
    if (!vst[u] && check_cycle(u)) {
      cout << "-1\n";
      return;
    }
  }

  priority_queue<int, vector<int>, greater<int>> q;
  for (int u = 1; u <= n; u++) {
    if (deg[u] == 0) q.push(u);
    // cout << u << " " << deg[u] << "\n";
  }
  vector<int> topo;
  while (!q.empty()) {
    int u = q.top();
    q.pop();
    topo.push_back(u);
    // cout << u << " " << '\n';
    for (int v : adj[u]) {
      deg[v]--;
      // cout << v << " " << deg[v] << "\n";
      if (deg[v] == 0) q.push(v);
    }
  }
  vector<int> res(n + 1);
  for (int val = 1; val <= n; val++) {
    int pos = topo[val - 1];
    res[pos] = val;
  }
  for (int v = 1; v <= n; v++) cout << res[v] << " ";
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
// 1 4 5 2 3
// 4 2 3

// 1 4 5 3 2
// 1
