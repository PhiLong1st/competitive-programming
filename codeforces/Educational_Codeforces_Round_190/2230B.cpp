/*
 Code by: KoKoDuDu
 Created: 2026.05.27 10:17:52
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

  int cnt4 = 0, cnt2 = 0, cnt13 = 0;
  int way = kMaxInf;
  for (char& c : s) {
    cnt4 += c == '4';
    cnt2 += c == '2';
    cnt13 += c == '1' || c == '3';
  }

  int tmp13 = 0, tmp2 = 0;
  way = min(cnt2, cnt13);
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (c == '4') continue;

    tmp13 += c == '1' || c == '3';
    tmp2 += c == '2';

    int way2 = tmp13 + cnt2 - tmp2;
    way = min({way, way2});
  }

  cout << cnt4 + (way == kMaxInf ? 0 : way) << '\n';
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
