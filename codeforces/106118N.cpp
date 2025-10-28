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

struct FFT {
  const int MOD, PR;
  const double PI = acos(-1);

  FFT(int MOD, int pR) : MOD(MOD), PR(pR) {}

  int modpow(int a, int e) {
    int r = 1;
    while (e) {
      if (e & 1) r = r * a % MOD;
      a = a * a % MOD;
      e >>= 1;
    }
    return r;
  }

  void ntt(vector<int>& a, bool invert) {
    int n = (int)a.size();
    vector<int> rev;
    static vector<int> roots{0, 1};

    if ((int)rev.size() != n) {
      int k = __builtin_ctz(n);
      rev.assign(n, 0);
      for (int i = 0; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    }

    if ((int)roots.size() < n) {
      int k = __builtin_ctz((int)roots.size());
      roots.resize(n);
      while ((1 << k) < n) {
        int z = modpow(PR, (MOD - 1) >> (k + 1));
        for (int i = 1 << (k - 1); i < (1 << k); ++i) {
          roots[2 * i] = roots[i];
          roots[2 * i + 1] = roots[i] * z % MOD;
        }
        ++k;
      }
    }

    for (int i = 0; i < n; i++)
      if (i < rev[i]) swap(a[i], a[rev[i]]);

    for (int len = 1; len < n; len <<= 1) {
      for (int i = 0; i < n; i += 2 * len) {
        for (int j = 0; j < len; ++j) {
          int u = a[i + j];
          int v = a[i + j + len] * roots[len + j] % MOD;
          int x = u + v;
          if (x >= MOD) x -= MOD;
          int y = u - v;
          if (y < 0) y += MOD;
          a[i + j] = x;
          a[i + j + len] = y;
        }
      }
    }

    if (invert) {
      reverse(a.begin() + 1, a.end());
      int inv_n = modpow(n, MOD - 2);
      for (int& z : a) z = z * inv_n % MOD;
    }
  }

  vector<int> conv(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int need = (int)a.size() + (int)b.size() - 1;

    int n = 1;
    while (n < need) n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<int> res(need);
    for (int i = 0; i < need; i++) res[i] = (int)llround(fa[i].real());

    return res;
  }

  void fft(vector<cd>& a, bool invert) {
    int n = (int)a.size(), sz = 31 - __builtin_clz(n);

    if (invert)
      for (auto& z : a) z = conj(z);

    vector<complex<long double>> r(2, 1);
    vector<cd> rt(2, 1);

    for (int k = 2; k < n; k *= 2) {
      r.resize(n);
      rt.resize(n);

      auto x = polar(1.0L, acosl(-1.0L) / k);
      for (int i = k; i < 2 * k; ++i)
        rt[i] = r[i] = (i & 1) ? r[i / 2] * x : r[i / 2];
    }

    vector<int> rev(n);
    for (int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << sz) / 2;

    for (int i = 0; i < n; ++i) {
      if (i >= rev[i]) continue;
      swap(a[i], a[rev[i]]);
    }

    for (int k = 1; k < n; k *= 2) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; ++j) {
          auto x = (double*)&rt[j + k], y = (double*)&a[i + j + k];
          cd z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
          a[i + j + k] = a[i + j] - z;
          a[i + j] += z;
        }
      }
    }

    if (!invert) return;
    for (auto& z : a) z = conj(z) / (double)n;
  }

  vector<int> conv_mod(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) return {};
    vector<int> res((int)a.size() + (int)b.size() - 1);

    int bit = 32 - __builtin_clz((int)res.size());
    int n = 1 << bit;
    int cut = (int)(sqrt((double)MOD));

    vector<cd> l(n), r(n), outs(n), outl(n);
    for (int i = 0; i < a.size(); ++i) l[i] = cd(a[i] / cut, a[i] % cut);
    for (int i = 0; i < b.size(); ++i) r[i] = cd(b[i] / cut, b[i] % cut);

    fft(l, false);
    fft(r, false);

    for (int i = 0; i < n; ++i) {
      int j = -i & (n - 1);
      outl[j] = (l[i] + conj(l[j])) * r[i] / (2.0 * n);
      outs[j] = (l[i] - conj(l[j])) * r[i] / (2.0 * n) / cd(0, 1);
    }

    fft(outl, false);
    fft(outs, false);

    for (int i = 0; i < res.size(); ++i) {
      int av = llround(real(outl[i]));
      int cv = llround(imag(outs[i]));
      int bv = llround(imag(outl[i])) + llround(real(outs[i]));
      res[i] =
          (((av % MOD + MOD) % MOD * cut + (bv % MOD + MOD) % MOD) % MOD * cut +
           (cv % MOD + MOD) % MOD) %
          MOD;
    }

    return res;
  }
};

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n), x(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> x[i];

  FFT fft(kMod, 3);

  auto conv1 = fft.conv(a, x);
  vector<int> b0(n, 0);
  for (int i = 1; i < n; i++) b0[i] = b[i];

  vector<int> r = b0;
  reverse(r.begin(), r.end());

  auto conv2 = fft.conv(x, r);
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