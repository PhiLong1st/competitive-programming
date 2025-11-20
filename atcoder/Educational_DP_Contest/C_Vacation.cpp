/*
    Code by: KoKoDuDu
    Created: 2025.11.18 20:51:06
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
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];

  vector<vector<int>> dp(n, vector<int>(3));
  dp[0][0] = a[0], dp[0][1] = b[0], dp[0][2] = c[0];
  for (int i = 1; i < n; ++i) {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
    dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
  }

  cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}