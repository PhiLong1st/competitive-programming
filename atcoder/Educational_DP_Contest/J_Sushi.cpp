/*
 Code by: KoKoDuDu
 Created: 2025.12.02 22:23:29
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
  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) cin >> x;

  int c1 = 0, c2 = 0, c3 = 0;
  for (int& x : a) c1 += (x == 1), c2 += (x == 2), c3 += (x == 3);

  vector<vector<vector<double>>> dp(
      n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1.0)));

  auto f = [&](auto&& f, int x, int y, int z) -> double {
    if (x == 0 && y == 0 && z == 0) return 0.0;

    auto& res = dp[x][y][z];
    if (res != -1) return res;

    int s = x + y + z;
    double ans = (double)n;

    if (x > 0) ans += 1.0 * x * f(f, x - 1, y, z);
    if (y > 0) ans += 1.0 * y * f(f, x + 1, y - 1, z);
    if (z > 0) ans += 1.0 * z * f(f, x, y + 1, z - 1);

    ans /= (double)s;
    return res = ans;
  };

  cout << fixed << setprecision(9) << f(f, c1, c2, c3);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
