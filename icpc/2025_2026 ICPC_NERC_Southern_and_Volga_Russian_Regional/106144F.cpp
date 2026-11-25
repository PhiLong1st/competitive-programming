/*
 Code by: KoKoDuDu
 Created: 2025.12.06 20:03:41
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

  vector<string> a(n);
  for (string& s : a) cin >> s;

  int cnt_2 = 0, cnt_3 = 0;
  for (string& s : a) {
    string pf = s.substr(0, 3);
    string sf = s.substr(3, 3);

    cnt_2 += (pf == "xx.") || (sf == "xx.");
    cnt_2 += (pf == ".xx") || (sf == ".xx");
    cnt_3 += (pf == "xxx") || (sf == "xxx");
  }

  auto f = [&](int x, int y) -> bool {
    if (y == 0) return x % 2 == 0;
    if (x == 0) return y % 2 == 0;
    if (x % 2) return 0;
    return y % 2 == 0;
  };

  // 0 Mono, 1 Poly
  int res = f(cnt_2, cnt_3);
  cout << ((!res) ? "Monocarp" : "Polycarp") << '\n';
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
