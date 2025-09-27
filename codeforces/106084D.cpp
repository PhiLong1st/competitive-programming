/*
    Code by: KoKoDuDu
    Created: 2025.09.27 13:51:54
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  s = " " + s;

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int sz = 2; sz <= n; ++sz) {
    for (int i = 1; i + sz - 1 <= n; ++i) {
      int l = i, r = l + sz - 1;

      if (s[l] == s[r]) {
        dp[l][r] = dp[l + 1][r - 1];
      } else {
        dp[l][r] = min({dp[l + 1][r - 1], dp[l + 1][r], dp[l][r - 1]}) + 1;
      }
    }
  }

  cout << dp[1][n] << '\n';
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