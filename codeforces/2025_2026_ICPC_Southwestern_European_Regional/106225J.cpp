/*
 Code by: KoKoDuDu
 Created: 2025.12.08 22:02:55
*/

#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second

using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

void add_mod(int& a, int b) { a = a + b >= kMod ? a + b - kMod : a + b; }

void minus_mod(int& a, int b) { a = (a - b + kMod) % kMod; }

void mul_mod(int& a, int b) { a = a * b % kMod; }

void maximize(int& x, int y) { x = max(x, y); }

void minimize(int& x, int y) { x = min(x, y); }

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res;
}

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];

  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  vector<vector<int>> pf(m + 1, vector<int>(n + 1));

  if (a[1] == b[1]) dp[1][1] = 1;
  for (int i = b[1]; i <= n; ++i) dp[i][1] = 1;

  for (int j = 1; j <= m; ++j)
    for (int i = 1; i <= n; ++i) pf[j][i] |= (pf[j][i - 1] | dp[i][j]);

  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      if (a[i] == b[j]) dp[i][j] |= dp[i - 1][j - 1];
      if (i <= b[j]) continue;
      dp[i][j] |= pf[j - 1][i - b[j]];
    }
    for (int j = 2; j <= m; ++j) pf[j][i] |= (pf[j][i - 1] | dp[i][j]);
  }
  cout << (dp[n][m] ? "YES" : "NO") << '\n';
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
