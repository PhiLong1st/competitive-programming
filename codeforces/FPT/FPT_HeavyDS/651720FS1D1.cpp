/*
 Code by: KoKoDuDu
 Created: 2025.11.19 10:07:48
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

// #ifdef ONLINE_JUDGE
// #define dbg(...)
// #else
// #include "debug.h"
// #endif

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

int add_mod(int a, int b) { return a + b >= kMod ? a + b - kMod : a + b; }

int minus_mod(int a, int b) { return (a - b + kMod) % kMod; }

int mul_mod(int a, int b) { return a * b % kMod; }

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
  int n, k;
  cin >> n >> k;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, kMinInf));

  for (int i = 0; i <= n; ++i) dp[i][0] = 0;
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      int val = max(a[1], a[i] - 5);
      int pos = lower_bound(a.begin() + 1, a.end(), val) - a.begin();
      int cost = i - pos + 1;
      maximize(dp[i][j], dp[pos - 1][j - 1] + cost);
      maximize(dp[i][j], dp[i - 1][j]);
    }
  }

  cout << *max_element(dp[n].begin(), dp[n].end());
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
