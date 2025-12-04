/*
    Code by: KoKoDuDu
    Created: 17.02.2025 14:12:50
    Link: https://codeforces.com/problemset/problem/1611/E1
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
  int k, n;
  cin >> n >> k;
  vector<vector<int>> adj(n + 1, vector<int>());
  vector<int> dp(n + 1, INT_MAX);
  vector<int> dist(n + 1, INT_MAX);
  queue<int> que;
  for (int i = 1; i <= k; ++i) {
    int x;
    cin >> x;
    dp[x] = 0;
    que.push(x);
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].emplace_back(y);
    adj[y].emplace_back(x);
  }
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    for (int g : adj[x]) {
      if (dp[g] > dp[x] + 1) {
        dp[g] = dp[x] + 1;
        que.push(g);
      }
    }
  }
  dist[1] = 0;
  que.push(1);
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    for (int g : adj[x]) {
      if (dist[g] > dist[x] + 1) {
        dist[g] = dist[x] + 1;
        que.push(g);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (adj[i].size() == 1) {
      if (dist[i] < dp[i]) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}