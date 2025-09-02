/*
    Code by: KoKoDuDu
    Created: 2025.08.26 11:02:08
*/

#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int kMaxValue = 1e9 + 1;
const int kMaxStep = 30;
const int kMod = 1e9 + 7;

void solve() {
  int num_nodes, num_edges, num_queries;
  cin >> num_nodes >> num_edges >> num_queries;

  vector<vector<int>> dist(kMaxStep + 1, vector<int>(num_nodes, 1));
  vector<array<int, 3>> edges(num_edges + 1);

  for (int i = 0; i < num_edges; i++) {
    int u, v, weight;
    cin >> u >> v >> weight;
    --u, --v;
    edges[i] = {u, v, weight};
  }

  for (int step = 1; step <= kMaxStep; step++) {
    for (int i = 0; i < num_edges; i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      int w = edges[i][2];
      int newValue = min(1LL * dist[step - 1][v] * w, kMaxValue * 1LL);
      dist[step][u] = max(dist[step][u], newValue);
    }
  }

  for (int i = 0; i < num_queries; i++) {
    int s, k;
    cin >> s >> k;
    --s;
    for (int step = 0; step <= kMaxStep; step++) {
      if (dist[step][s] > k) {
        cout << step << '\n';
        break;
      }
    }
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