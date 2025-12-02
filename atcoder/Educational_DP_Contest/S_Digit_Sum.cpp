/*
 Code by: KoKoDuDu
 Created: 2025.12.01 19:10:55
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
  string s;
  cin >> s;

  int d;
  cin >> d;

  int n = (int)s.size();

  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(d, -1)));

  // 0: =, 1: <
  auto f = [&](auto&& f, int pos, int status, int rem) -> int {
    if (pos == (int)s.size()) return (rem == 0);

    auto& res = dp[pos][status][rem];
    if (res != -1) return res;

    int lim = status ? 9 : (s[pos] - '0');
    int ans = 0;
    for (int x = 0; x <= lim; ++x) {
      int new_rem = (rem + x) % d;
      int new_status = status ? status : (x < lim);
      int add = f(f, pos + 1, new_status, new_rem);
      ans = (ans + add) % kMod;
    }
    return res = ans;
  };

  int ans = (f(f, 0, 0, 0) - 1 + kMod) % kMod;
  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
