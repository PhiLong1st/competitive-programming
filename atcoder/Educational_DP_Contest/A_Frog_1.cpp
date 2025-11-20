/*
    Code by: KoKoDuDu
    Created: 2025.11.18 20:37:14
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

  vector<int> a(n), dp(n, kMaxInf);
  for (auto& x : a) cin >> x;

  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    if (i > 0) dp[i] = min(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
    if (i > 1) dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
  }
  cout << dp[n - 1];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}