/*
    Code by: KoKoDuDu
    Created: 2025.11.06 16:30:31
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
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& x : a) cin >> x;

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));

  dp[1][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int k = 0; k < n; ++k) {
      for (int h = k; h <= n; ++h) {
        dp[i][k + 1] += (dp[i - 1][h] * fpow(2, k)) % kMod;
        dp[i][k + 1] %= kMod;
      }
    }
  }

  int ans = 0;
  for (int h = 0; h < n; ++h) ans = (ans + dp[n][h]) % kMod;
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