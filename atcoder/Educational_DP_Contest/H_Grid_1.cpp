/*
    Code by: KoKoDuDu
    Created: 2025.11.18 22:55:27
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

void add_mod(int& a, int b) { a = (a + b >= kMod) ? (a + b - kMod) : (a + b); }

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char x;
      cin >> x;
      a[i][j] = (x == '#');
    }
  }

  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  dp[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i - 1][j] == 0) add_mod(dp[i][j], dp[i - 1][j]);
      if (a[i][j - 1] == 0) add_mod(dp[i][j], dp[i][j - 1]);
    }
  }
  cout << dp[n][m];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}