/*
 Code by: KoKoDuDu
 Created: 2026.05.25 12:53:59
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

  vector<int> a(n), b(n), pf_max(n), sf_max(n);
  for (int& x : a) cin >> x;
  for (int& x : b) cin >> x;

  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) swap(a[i], b[i]);
  }

  sf_max[n - 1] = b[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    sf_max[i] = max(sf_max[i + 1], b[i]);
  }

  pf_max[0] = b[0];
  for (int i = 1; i < n; ++i) {
    pf_max[i] = max(pf_max[i - 1], b[i]);
  }

  int sum = accumulate(a.begin(), a.end(), 0LL);

  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (i < n - 1 && a[i] < sf_max[i + 1]) continue;
    if (i > 0 && a[i] < pf_max[i - 1]) continue;
    res = max(res, a[i] + sum - a[i] + b[i]);
  }

  for (int i = 0; i < n; ++i) {
    if (i < n - 1 && b[i] < sf_max[i + 1]) continue;
    if (i > 0 && b[i] < pf_max[i - 1]) continue;
    res = max(res, b[i] + sum);
  }
  cout << res << '\n';
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
