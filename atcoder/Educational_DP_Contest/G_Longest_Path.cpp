/*
    Code by: KoKoDuDu
    Created: 2025.11.18 22:40:57
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
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1, vector<int>());
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  vector<int> seen(n + 1), dist(n + 1, 0);
  auto calc = [&](auto&& calc, int x) -> void {
    seen[x] = 1;
    for (auto& v : adj[x]) {
      if (seen[v]) continue;
      calc(calc, v);
    }
    for (auto& v : adj[x]) dist[x] = max(dist[x], dist[v] + 1);
  };

  for (int i = 1; i <= n; ++i) {
    if (seen[i]) continue;
    calc(calc, i);
  }
  cout << *max_element(dist.begin(), dist.end());
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}