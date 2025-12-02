/*
 Code by: KoKoDuDu
 Created: 2025.12.02 22:45:46
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

  // int x = (n + 1) / 2, y = (n + 1) / 2;
  // int ans = 0;
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     ans += max(abs(x - i), abs(y - j));
  //     cerr << max(abs(x - i), abs(y - j));
  //   }
  //   cerr << '\n';
  // }
  // cout << ans << '\n';

  int dist = n / 2;
  int temp = n;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res += (4 * temp - 2) * dist;
    temp--, dist--;
  }
  cout << res << '\n';
}

/*
.....
.....
..x..
.....
.....
*/

//(a, b) -> (x, y);

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
