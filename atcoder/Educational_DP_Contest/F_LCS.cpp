/*
    Code by: KoKoDuDu
    Created: 2025.11.18 21:49:49
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

void solve() {
  string s, t;
  cin >> s >> t;

  int n = s.size();
  int m = t.size();

  s = " " + s;
  t = " " + t;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  string res = "";
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (s[i] == t[j]) {
      res += s[i];
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  reverse(res.begin(), res.end());
  cout << res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}