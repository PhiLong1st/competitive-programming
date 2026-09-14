/*
 Code by: KoKoDuDu
 Created: 2026.09.05 22:02:45
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

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int last = -1;
  int best = 0;
  pii ans = {-1, -1};

  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) continue;

    if (last != -1 && best < i - last + 1) {
      best = i - last + 1;
      ans = {last, i};
    }

    if (last == -1) last = i;

    last = a[i] == 1 ? i : last;
  }

  if (best != 0) a[ans.first] = a[ans.second] = 1;

  for (int i = ans.first + 1; i < ans.second; ++i) {
    if (a[i] == -1) a[i] = 0;
  }

  for (int i = 1; i <= n; ++i) {
    if (a[i] == -1) a[i] = 1;
  }

  for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << '\n';
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