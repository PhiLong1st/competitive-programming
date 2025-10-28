/*
    Code by: KoKoDuDu
    Created: 2025.10.28 22:09:49
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

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1), c(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> c[i];

  int ans = 0;
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) dp[i] = c[i], ans = max(ans, dp[i]);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (a[i] < a[j]) continue;
      dp[i] = max(dp[i], dp[j] + c[i]);
      ans = max(ans, dp[i]);
    }
  }

  int sum = accumulate(c.begin(), c.end(), 0LL);
  cout << sum - ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}