/*
    Code by: KoKoDuDu
    Created: 2025.11.18 20:56:22
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
  int n, lim;
  cin >> n >> lim;

  vector<int> v(n), w(n);
  for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];

  vector<int> dp(lim + 1);
  for (int i = 0; i < n; ++i) {
    for (int c = lim; c >= w[i]; --c) {
      dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
    }
  }

  cout << *max_element(dp.begin(), dp.end());
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}