/*
 Code by: Algorillas
 Created: 2026.09.23 21:38:51
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
  int n, energy, k, r;
  cin >> n >> energy >> k >> r;
  vector<array<int, 2>> a(n);
  for (auto& c : a) cin >> c[0] >> c[1];
  int T = min(r, 100ll);
  vector<vector<int>> dp(T + 1, vector<int>((1 << n) + 1, -1));
  vector<int> is_valid((1 << n) + 1, 0);
  unordered_map<int, int> pattern;

  for (int mask = 0; mask < (1 << n); ++mask) {
    int sum_energy = 0, sum_v = 0;
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) {
        sum_energy += a[i][1];
        sum_v += a[i][0];
      }
    }
    if (sum_energy <= energy) {
      dp[1][mask] = sum_v;
      is_valid[mask] = 1;
      pattern[mask] = 0;
    }
  }
  dbg(dp[1]);

  for (int i = 2; i <= T; ++i) {
    for (int pre_mask = 0; pre_mask < (1 << n); ++pre_mask) {
      if (dp[i - 1][pre_mask] == -1) continue;

      for (int mask = 0; mask < (1 << n); ++mask) {
        if (!is_valid[mask]) continue;

        int sum_v = 0, sum_energy = k * __builtin_popcount(pre_mask & mask);
        for (int j = 0; j < n; ++j) {
          if (mask >> j & 1) {
            sum_v += a[j][0];
            sum_energy += a[j][1];
          }
        }
        if (sum_energy > energy) continue;

        dp[i][mask] = max(dp[i][mask], dp[i - 1][pre_mask] + sum_v);
      }
    }
    dbg(i, dp[i]);
  }

  dbg(dp[T]);

  cout << *max_element(all(dp[T])) << '\n';
}

void solve1() {
  int n, limit, k, round;
  cin >> n >> limit >> k >> round;
  vector<int> damage(n), cost(n);
  for (int i = 0; i < n; i++) {
    cin >> damage[i] >> cost[i];
  }
  vector<array<int, 3>> correct;
  for (int mask = 1; mask < (1LL << n); mask++) {
    int d = 0, c = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        d += damage[i];
        c += cost[i];
      }
    }
    if (c <= limit) {
      correct.push_back({mask, d, c});
    }
  }
  if (correct.empty()) {
    cout << 0 << "\n";
    return;
  }
  int num_node = correct.size();
  vector<vector<int>> adj(correct.size(), vector<int>());
  for (int i = 0; i < correct.size(); i++) {
    for (int j = 0; j < correct.size(); j++) {
      int mi = correct[i][0];
      int mj = correct[j][0];
      int common = __builtin_popcount(mi & mi);
      if (correct[j][2] + common * k <= limit) {
        adj[i].push_back(j);
      }
    }
  }

  vector<int> color(num_node), path;
  function<void(int)> dfs = [&](int u) {
    color[u] = 1;
    path.push_back(u);
    for (int v : adj[u]) {
      if (color[v] == 1) {
        // cycle
      }
      else {
        
      }

      
    }
    color[u] = 2;
   };
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve1();
  return 0;
}