/*
    Code by: KoKoDuDu
    Created: 2025.11.17 17:42:38
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
#define el '\n'
#define problem "problem"

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

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1), pf(n + 1), sf(n + 1);

  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i <= n; ++i) pf[i] = gcd(pf[i - 1], a[i]);

  sf[n] = a[n];
  for (int i = n - 1; i >= 1; --i) sf[i] = gcd(sf[i + 1], a[i]);

  int res = 0;
  for (int i = 2; i <= n; ++i) res += min(sf[i], pf[i]);
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}