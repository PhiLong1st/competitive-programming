/*
    Code by: KoKoDuDu
    Created: 2025.11.12 21:59:39
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
const int kMod = 998244353;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

void solve() {
  int n, k;
  cin >> n >> k;

  int lim = min(n, k);
  vector<vector<int>> dp(lim + 1, vector<int>(k + 1));

  for (int t = 1; t <= k; ++t) dp[1][t] = 1;

  for (int i = 1; i < lim; ++i) {
    for (int t = 1; t <= k; ++t) {
      int l = max(1LL, ceil_div(i * t + 1, i + 1));
      int r = min(k, floor_div(i * t + k, i + 1));

      for (int j = l; j <= r; ++j)
        dp[i + 1][j] = (dp[i + 1][j] + dp[i][t]) % kMod;
    }
  }

  int ans = 0;
  for (int t = 1; t <= k; ++t) ans = (ans + dp[lim][t]) % kMod;
  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}