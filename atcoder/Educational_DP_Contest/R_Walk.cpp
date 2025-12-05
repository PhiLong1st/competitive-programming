/*
 Code by: KoKoDuDu
 Created: 2025.12.03 13:24:20
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

struct Matrix {
  int r, c;
  vector<vector<int>> mtx;
  Matrix(int r, int c) : r(r), c(c), mtx(r, vector<int>(c)) {}
};

Matrix operator*(const Matrix& mtx_a, const Matrix& mtx_b) {
  Matrix mtx_res(mtx_a.r, mtx_b.c);
  for (int i = 0; i < mtx_a.r; i++) {
    for (int j = 0; j < mtx_b.c; j++) {
      int val = 0;
      for (int k = 0; k < mtx_a.c; k++) {
        val += (mtx_a.mtx[i][k] * mtx_b.mtx[k][j]) % kMod;
        if (val >= kMod) val -= kMod;
      }
      mtx_res.mtx[i][j] = val;
    }
  }
  return mtx_res;
}

Matrix fpow(const Matrix& x, int y) {
  Matrix res(x.r, x.c);
  for (int i = 0; i < min(x.r, x.c); i++) res.mtx[i][i] = 1;
  Matrix cur = x;
  while (y) {
    if (y & 1) res = res * cur;
    cur = cur * cur;
    y >>= 1;
  }
  return res;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> a[i][j];

  Matrix f(1, n);
  for (int i = 0; i < n; ++i) f.mtx[0][i] = 1;

  Matrix trans_f(n, n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) trans_f.mtx[i][j] = a[j][i];

  trans_f = fpow(trans_f, k);
  f = f * trans_f;

  int ans = 0;
  for (int i = 0; i < n; ++i) add_mod(ans, f.mtx[0][i]);
  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
