/*
 Code by: KoKoDuDu
 Created: 2026.04.07 23:10:07
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

int solve() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  int g1 = __gcd(a, n);
  int g2 = __gcd(b, m);
  if (g1 != 1 || g2 != 1) return 0;

  int g = __gcd(n, m);
  if (g == 1) return 1;
  if (n == m && n <= 2) return 1;
  if (g == min(n, m)) return 1;
  return 0;
  // cerr << g;
}

// 0 a1 a2 a3
// 0 b1
// 0 0 -> a1 0 -> a1 b1 -> a1 0 -> a2 0 -> a2 b1 -> a3 b1 -> a3 0 -> 0 0 -> 0 1

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) cout << (solve() ? "YES" : "NO") << "\n";
  return 0;
}
