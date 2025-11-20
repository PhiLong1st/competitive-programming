/*
    Code by: KoKoDuDu
    Created: 2025.11.18 21:16:49
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
  int n, lim;
  cin >> n >> lim;

  vector<int> v(n), w(n);
  for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];

  int total = accumulate(v.begin(), v.end(), 0LL);
  vector<int> dp(total + 1, kMaxInf);

  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int val = total; val >= v[i]; --val) {
      dp[val] = min(dp[val], dp[val - v[i]] + w[i]);
    }
  }

  for (int val = total; val >= 0; --val) {
    if (dp[val] > lim) continue;
    // cerr << val << ' ' << dp[val] << '\n';
    cout << val;
    break;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}