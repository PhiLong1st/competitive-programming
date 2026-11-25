/*
 Code by: Algorillas
 Created: 2026.11.09 21:07:47
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<array<int, 2>> d(n + 1, {INF, 0});
  deque<int> q;
  d[1] = {0, 1};
  q.push_back(1);

  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    // cerr << u <<  " " << d[u][0] << " " << d[u][1] << "\n";

    for (int v : adj[u]) {
      if (d[v][0] == d[u][0] + 1) {
        d[v][1] += d[u][1];
        q.push_front(v);
      } else if (d[v][0] > d[u][0] + 1) {
        d[v][1] = d[u][1];
        d[v][0] = d[u][0] + 1;
        q.push_back(v);
      }
    }
  }

  int cnt = 0;
  queue<int> q2;
  q2.push(n);
  vector<bool> vst(n + 1);
  vst[n] = true;
  while (!q2.empty()) {
    int u = q2.front();
    q2.pop();
    for (int v : adj[u]) {
      if (vst[v]) continue;
      vst[v] = true;
      q2.push(v);
    }
  }

  for (int u = 1; u < n; u++) {
    for (int v : adj[u]) {
      if (v < u) continue;
      if (d[u][0] + 1 > d[v][0]) {
        cerr << u << " " << v << "\n";
        cnt++;
      }
    }
  }

  if (cnt == 1) {
    cout << "possible";
  } else {
    cout << "impossible";
  }
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