/*
 Code by: Algorillas
 Created: 2026.11.09 21:58:26
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;

  vector<int> a(2 * n + 1), b(2 * n + 1), c(2 * n + 1), val(2 * n + 1);
  map<int, int> mp;

  for (int i = 1; i <= 2 * n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    val[i] = a[i] - b[i];
    mp[c[i]]++;
  }

  int sumB = accumulate(b.begin(), b.end(), 0ll);

  int bonus = 0;
  for (auto& [x, y] : mp) bonus += x * (y / 2);

  vector<vector<int>> dp(2 * n + 1, vector<int>(n + 1, INT_MIN));
  for (int i = 1; i <= 2 * n; ++i) dp[i][0] = 0;

  for (int i = 1; i <= 2 * n; ++i) {
    for (int k = 1; k <= n; ++k) {
      for (int j = 1; j < i; ++j) {
        dp[i][k] = max(dp[i][k], dp[j][k - 1] + val[i]);
      }
    }
  }

  cerr << bonus << '\n';
  cerr << sumB << '\n';
  for (int i = 1; i <= 2 * n; ++i) cerr << val[i] << ' ';
  cerr << '\n';

  cerr << dp[2 * n][n] << '\n';

  cout << dp[2 * n][n] + bonus + sumB << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}