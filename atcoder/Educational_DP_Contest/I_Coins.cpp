#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define db double
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
  int n;
  cin >> n;

  vector<db> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<db>> dp(n + 1, vector<db>(n + 1));
  dp[0][0] = 1.0;
  for (int i = 1; i <= n; ++i) {
    db head_rate = a[i], tail_rate = (1 - a[i]);
    dp[i][0] = dp[i - 1][0] * tail_rate;
    for (int head = i; head >= 1; --head) {
      dp[i][head] += dp[i - 1][head - 1] * head_rate;
      dp[i][head] += dp[i - 1][head] * tail_rate;
    }
  }

  db ans = 0.0;
  for (int head = (n + 1) / 2; head <= n; ++head) ans += dp[n][head];
  cout << fixed << setprecision(10) << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
