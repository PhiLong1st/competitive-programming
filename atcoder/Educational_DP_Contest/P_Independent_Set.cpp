/*
 Code by: KoKoDuDu
 Created: 2025.12.01 18:07:23
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

void add_mod(int& a, int b) { a = a + b >= kMod ? a + b - kMod : a + b; }

void minus_mod(int& a, int b) { a = (a - b + kMod) % kMod; }

void mul_mod(int& a, int b) { a = a * b % kMod; }

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
  int n;
  cin >> n;

  if (n == 1) return void(cout << 2);

  vector<vector<int>> adj(n + 1, vector<int>()), dp(n + 1, vector<int>(2));

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto dfs = [&](auto&& dfs, int x, int p) -> void {
    dp[x][0] = 1;
    dp[x][1] = 1;

    if (adj[x].size() == 1 && x != 1) return;

    for (int& v : adj[x]) {
      if (v == p) continue;

      dfs(dfs, v, x);

      dp[x][0] = dp[x][0] * ((dp[v][0] + dp[v][1]) % kMod) % kMod;
      dp[x][1] = dp[x][1] * dp[v][0] % kMod;
    }
  };

  dfs(dfs, 1, 0);
  cout << (dp[1][0] + dp[1][1]) % kMod;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
