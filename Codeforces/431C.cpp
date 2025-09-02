/*
    Code by: KoKoDuDu
    Created: 2025.09.02 23:18:04
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n, maxStep, minStep;
  cin >> n >> maxStep >> minStep;

  vector<vector<int>> dp(n + 1, vector<int>(2, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int step = 1; step <= min(maxStep, i); ++step) {
      if (step < minStep) {
        dp[i][0] = (dp[i][0] + dp[i - step][0]) % kMod;
      } else {
        dp[i][1] = (dp[i][1] + dp[i - step][0]) % kMod;
      }
      dp[i][1] = (dp[i][1] + dp[i - step][1]) % kMod;
    }
  }

  cout << dp[n][1];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}