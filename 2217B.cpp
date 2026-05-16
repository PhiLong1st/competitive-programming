/*
 Code by: KoKoDuDu
 Created: 2026.04.07 22:01:27
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
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int& c : a) cin >> c;

  vector<int> b(k);
  for (int& c : b) cin >> c;

  b[0]--;
  int val = a[b[0]];
  int ans = 0;

  int l = 0, r = n - 1;
  while (a[l] == val && l < b[0]) l++;
  while (a[r] == val && r > b[0]) r--;

  if (l == r) {
    cout << 0 << "\n";
    return;
  }

  int cnt1 = 1, cnt2 = 1;
  for (int i = l + 1; i <= b[0]; ++i) {
    cnt1 += a[i] != a[i - 1];
  }

  for (int i = r; i > b[0]; --i) {
    cnt2 += a[i] != a[i - 1];
  }

  // cerr << b[0] << ' ' << val << '\n';
  // cerr << l << ' ' << r << '\n';
  // cerr << cnt1 << ' ' << cnt2 << '\n';

  cout << max(cnt1, cnt2) + max(cnt1, cnt2) % 2 << '\n';
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
