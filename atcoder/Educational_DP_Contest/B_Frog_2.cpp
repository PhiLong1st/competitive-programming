/*
    Code by: KoKoDuDu
    Created: 2025.11.18 20:45:47
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
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto& x : a) cin >> x;

  vector<int> dp(n, kMaxInf);
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (i - j < 0) break;
      dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
    }
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