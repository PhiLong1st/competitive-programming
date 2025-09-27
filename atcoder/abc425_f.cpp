/*
    Code by: KoKoDuDu
    Created: 2025.09.27 20:04:27
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 998244353;
const int kInf = 1e18;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> dp(1 << n, 0);
  dp[0] = 1;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int pre = -1;
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) {
        if (pre != s[i]) {
          dp[mask] += dp[mask ^ (1 << i)];
          dp[mask] %= kMod;
        }
        pre = s[i];
      }
    }
  }

  cout << dp[(1 << n) - 1];
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