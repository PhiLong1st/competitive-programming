/*
    Code by: KoKoDuDu
    Created: 2025.11.17 18:01:45
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
#define el '\n'

using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

int add_mod(int a, int b) { return a + b >= kMod ? a + b - kMod : a + b; }

int minus_mod(int a, int b) { return (a - b + kMod) % kMod; }

int mul_mod(int a, int b) { return a * b % kMod; }

void maximize(int& x, int y) { x = max(x, y); }

void minimize(int& x, int y) { x = min(x, y); }

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<int>> adj(n + 1, vector<int>());
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> seen(n + 1), dist(n + 1);
  queue<int> que;
  que.push(1);
  seen[1] = 1;
  dist[1] = 0;

  while (!que.empty()) {
    int x = que.front();
    que.pop();

    for (auto& v : adj[x]) {
      if (seen[v]) continue;
      seen[v] = true;
      dist[v] = dist[x] + 1;
      que.push(v);
    }
  }

  vector<int> res(k + 1);
  for (int i = 1; i <= n; ++i) maximize(res[a[i]], dist[i]);
  for (int i = 1; i <= k; ++i) cout << res[i] << ' ';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}