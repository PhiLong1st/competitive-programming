/*
    Code by: KoKoDuDu
    Created: 2025.10.03 12:47:24
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxBit = 17;
const int kMaxN = 100000 + 307;

int num_nodes, ans;
int parent_spt[kMaxN + 1][kMaxBit + 1], gcd_spt[kMaxN + 1][kMaxBit + 1];
int height[kMaxN + 1], values[kMaxN + 1];
vector<pair<int, int>> adj[kMaxN];

static inline int gcd(int a, int b) {
  while (b) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

void dfs(int u, int par) {
  for (auto [v, w] : adj[u]) {
    if (v == par) continue;
    height[v] = height[u] + 1;
    parent_spt[v][0] = u;
    gcd_spt[v][0] = w;
    dfs(v, u);
  }
}

void solve() {
  cin >> num_nodes;

  for (int i = 1; i <= num_nodes; ++i) cin >> values[i];

  for (int i = 1; i < num_nodes; ++i) {
    int u, v;
    cin >> u >> v;

    int w = gcd(values[u], values[v]);
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  int root = 1;
  height[root] = 1;

  dfs(root, 0);

  for (int bit = 1; bit <= kMaxBit; ++bit) {
    for (int v = 1; v <= num_nodes; ++v) {
      int mid = parent_spt[v][bit - 1];
      if (mid == 0) {
        continue;
      }

      parent_spt[v][bit] = parent_spt[mid][bit - 1];
      gcd_spt[v][bit] = gcd(gcd_spt[v][bit - 1], gcd_spt[mid][bit - 1]);
    }
  }

  for (int v = 1; v <= num_nodes; ++v) {
    int cur_node = v;
    int cur_gcd = values[v];

    while (cur_node != 0) {
      int temp = cur_node;

      for (int k = kMaxBit - 1; k >= 0; --k) {
        int anc = parent_spt[temp][k];
        if (anc == 0) continue;

        if (cur_gcd == 0 && gcd_spt[temp][k] == 0) temp = anc;

        if (cur_gcd != 0 && gcd_spt[temp][k] % cur_gcd == 0) temp = anc;
      }

      int len = height[cur_node] - height[temp] + 1;
      ans = (ans + (cur_gcd % kMod) * len) % kMod;

      int par = parent_spt[temp][0];
      if (par == 0) break;

      cur_node = par;
      cur_gcd = gcd(cur_gcd, values[cur_node]);
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) solve();
  return 0;
}
