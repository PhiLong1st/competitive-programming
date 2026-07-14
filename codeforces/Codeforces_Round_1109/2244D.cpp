/*
 Code by: KoKoDuDu
 Created: 2026.07.14 22:55:42
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
  int n, m;
  cin >> n >> m;

  vector<int> a(n + 1), b(m + 1), pf(n + 1);

  for (int i = 1; i <= n; ++i) cin >> a[i], pf[i] = pf[i - 1] + a[i];

  for (int i = 1; i <= m; ++i) cin >> b[i];

  sort(b.begin() + 1, b.end());

  int sum = pf[n];
  // for (int i = b[m] + 1; i <= n; ++i) sum += a[i];

  // 0 min, 1 max
  vector<vector<int>> f(n + 1, vector<int>(2));

  int minn = kMaxInf;
  int maxx = kMinInf;

  for (int i = 1; i <= m; ++i) {
    int posR = b[i];

    f[posR][0] = -pf[posR];
    f[posR][1] = -pf[posR];

    // for (int j = 0; j < i; ++j) {
    //   int posL = b[j];
    //   int change = -(pf[posR] - pf[posL]);

    //   f[posR][0] = min(f[posR][0], -f[posL][1] + change);
    //   f[posR][1] = max(f[posR][1], -f[posL][0] + change);
    // }

    f[posR][0] = min(f[posR][0], -pf[posR] - maxx);
    f[posR][1] = max(f[posR][1], -pf[posR] - minn);

    sum = max(sum, pf[n] - pf[posR] + f[posR][1]);
    sum = max(sum, pf[n] - pf[posR] + f[posR][0]);

    minn = min(minn, f[posR][0] - pf[posR]);
    maxx = max(maxx, f[posR][1] - pf[posR]);

    // cerr << f[posR][0] << ' ' << f[posR][1] << '\n';
  }

  cout << sum << '\n';

  // for (int i = 1; i <= n; ++i) cerr << pf[i] << ' ';
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
