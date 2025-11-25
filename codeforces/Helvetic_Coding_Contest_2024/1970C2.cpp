/*
 Code by: KoKoDuDu
 Created: 2025.11.24 17:44:43
*/

#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second

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

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

void solve() {
  int n, t;
  cin >> n >> t;

  vector<vector<int>> adj(n + 1, vector<int>());
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> f(n + 1);  // 0 win, 1 lose
  for (int i = 1; i <= n; ++i) f[i] = (adj[i].size() == 1);

  vector<int> par(n + 1);
  int root = 1;

  auto dfs = [&](auto&& dfs, int x, int p) -> void {
    if (adj[x].size() == 1 && x != root) {
      f[x] = 1;
      return;
    }

    for (auto& v : adj[x]) {
      if (v == p) continue;
      par[v] = x;
      dfs(dfs, v, x);
    }

    f[x] = 1;
    for (auto& v : adj[x]) {
      if (v == p) continue;

      if (f[v] == 1) {
        f[x] = 0;
        break;
      }
    }
  };

  while (t--) {
    int x;
    cin >> x;

    root = x;
    dfs(dfs, root, 0);
    cout << (!f[root] ? "Ron\n" : "Hermione\n");
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}