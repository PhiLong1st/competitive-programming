/*
 Code by: KoKoDuDu
 Created: 2025.11.24 14:30:27
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

int calc(int x) {
  if (x <= 0) return 0;
  if (x < 10) return x;

  string s = to_string(x);
  int n = s.size();
  int half = (n + 1) / 2;

  int ans = 0;
  for (int len = 1; len < n; ++len) {
    int add = 9;
    for (int i = 1; i < (len + 1) / 2; ++i) add *= 10;
    ans = ans + add;
  }

  int pf = 0;
  for (int i = 0; i < half; ++i) pf = pf * 10 + (s[i] - '0');

  int st = 1;
  for (int i = 1; i < half; ++i) st *= 10;

  ans += pf - st;

  string left = s.substr(0, half);
  string p = left;
  int pos = (n % 2 ? half - 2 : half - 1);
  for (int i = pos; i >= 0; --i) p.push_back(left[i]);

  if (p.size() == s.size() && p <= s) ans++;
  return ans;
}

void solve() {
  int l, r;
  cin >> l >> r;
  cout << calc(r) - calc(l - 1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
