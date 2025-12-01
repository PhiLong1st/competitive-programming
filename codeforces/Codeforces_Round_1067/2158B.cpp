/*
 Code by: KoKoDuDu
 Created: 2025.11.29 21:38:10
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

  vector<int> a(2 * n);
  for (int& x : a) cin >> x;

  map<int, int> cnt;
  for (int& x : a) cnt[x]++;

  int best = 0;
  int total = 0;

  int cnt_odd = 0;
  int cnt_even = 0;

  for (auto& [u, v] : cnt) {
    if (v % 2 == 0) {
      int t = v / 2;
      if (t % 2 != 0) {
        best += 2;
      } else {
        cnt_even++;
      }
    } else {
      best++;
      cnt_odd++;
    }
  }

  int rem = cnt_even % 2;
  int bonus = (cnt_even - cnt_even % 2) * 2;

  if (rem == 1) {
    if (cnt_odd >= 2) bonus += 2;
  }

  cout << best + bonus << '\n';
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
