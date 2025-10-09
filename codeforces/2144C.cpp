/*
    Code by: KoKoDuDu
    Created: 2025.10.09 18:54:11
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 998244353;
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

  vector<int> a(n + 2), b(n + 2), dp(n + 2);
  vector<vector<int>> is_desc(n + 1, vector<int>(n + 1));

  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i <= n; ++i) cin >> b[i];

  a[0] = b[0] = 0;
  a[n + 1] = b[n + 1] = kMaxInf;

  for (int i = 1; i <= n; ++i) {
    is_desc[i][i] = true;
    is_desc[i - 1][i] = (a[i] >= a[i - 1]) && (b[i] >= b[i - 1]);
  }

  for (int sz = 3; sz <= n; ++sz) {
    for (int i = 1; i + sz - 1 <= n; ++i) {
      int l = i, r = i + sz - 1;

      bool is_ok_a = (a[l] <= a[l + 1]) && (a[r - 1] <= a[r]);
      bool is_ok_b = (b[l] <= b[l + 1]) && (b[r - 1] <= b[r]);

      is_desc[l][r] = is_desc[l + 1][r - 1] && is_ok_a && is_ok_b;
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = i + 1; j <= n; ++j) {
  //     dbg(i, j, is_desc[i][j]);
  //   }
  // }

  dp[0] = 1;
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (j == i - 1) {
        if (a[i] < a[j] || b[i] < b[j]) continue;

        dp[i] = (dp[i] + dp[j]) % kMod;
      } else {
        if (a[i] < b[i - 1] || b[i] < a[i - 1]) continue;
        if (a[j] > b[j + 1] || b[j] > a[j + 1]) continue;
        if (!is_desc[j + 1][i - 1]) continue;

        // dbg(i, j);
        dp[i] = (dp[i] + dp[j]) % kMod;
      }
    }

    // dbg(i, dp[i]);
  }

  cout << dp[n + 1] << '\n';
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