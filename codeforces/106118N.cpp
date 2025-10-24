/*
    Code by: KoKoDuDu
    Created: 2025.10.24 16:48:36
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
using cd = complex<double>;

const double PI = acos(-1);
const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

static inline int cdiv(int a, int b) {
  return a >= 0 ? (a + b - 1) / b : a / b;
}

static inline int fdiv(int a, int b) {
  return a <= 0 ? (a - b + 1) / b : a / b;
}

static inline void add_mod(int& a, int b) {
  a = a + b;
  if (a >= kMod) a -= kMod;
}

static inline int mul_mod(int a, int b) {
  a = a * b % kMod;
  return a;
}

void fft(vector<cd>& a, bool invert) {
  int n = a.size();
  if (n == 1) return;

  vector<cd> a0(n / 2), a1(n / 2);
  for (int i = 0; 2 * i < n; i++) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }

  fft(a0, invert);
  fft(a1, invert);

  double ang = 2 * PI / n * (invert ? -1 : 1);
  cd w(1), wn(cos(ang), sin(ang));
  for (int i = 0; 2 * i < n; i++) {
    a[i] = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];
    w *= wn;

    if (!invert) continue;

    a[i] /= 2;
    a[i + n / 2] /= 2;
  }
}

vector<int> conv(vector<int> const& a, vector<int> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());

  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;

  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);

  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);

  vector<int> result(n);
  for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
  return result;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n), x(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> x[i];

  auto conv1 = conv(a, x);
  vector<int> b0(n, 0);
  for (int i = 1; i < n; i++) b0[i] = b[i];

  vector<int> r = b0;
  reverse(r.begin(), r.end());

  auto conv2 = conv(x, r);

  for (int i = 0; i < n; i++) {
    int y = (i < (int)conv1.size()) ? conv1[i] : 0;
    y += conv2[(n - 1) + i];
    cout << y << ' ';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}