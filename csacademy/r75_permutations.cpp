/*
    Code by: KoKoDuDu
    Created: 2025.10.24 19:03:09
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 998244353;
const int G = 3;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

struct Combinatorics {
  int n;
  vector<int> fact, inv, fact_inv;

  Combinatorics(int n) : n(n), fact(n + 1), inv(n + 1), fact_inv(n + 1) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      inv[i] = kMod - (kMod / i) * inv[kMod % i] % kMod;
    }

    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[i] = fact[i - 1] * i % kMod;
      fact_inv[i] = fact_inv[i - 1] * inv[i] % kMod;
    }
  }

  int get_nCk(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * fact_inv[k] % kMod * fact_inv[n - k] % kMod;
  }

  int get_inv_fact(int i) { return fact_inv[i]; }

  int get_fact(int i) { return fact[i]; }

  int get_inv(int i) { return inv[i]; }
};

struct FFT {
  const int kMod, kPr;

  FFT(int kMod, int pR) : kMod(kMod), kPr(pR) {}

  int modpow(int a, int e) {
    int r = 1;
    while (e) {
      if (e & 1) r = r * a % kMod;
      a = a * a % kMod;
      e >>= 1;
    }
    return r;
  }

  void fft(vector<cd>& a, bool invert) {
    int n = (int)a.size();
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

      if (invert) {
        a[i] /= 2;
        a[i + n / 2] /= 2;
      }
    }
  }

  void ntt(vector<int>& a, bool invert) {
    int n = (int)a.size();
    static vector<int> rev;
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
        int z = modpow(kPr, (kMod - 1) >> (k + 1));
        for (int i = 1 << (k - 1); i < (1 << k); ++i) {
          roots[2 * i] = roots[i];
          roots[2 * i + 1] = roots[i] * z % kMod;
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
          int v = a[i + j + len] * roots[len + j] % kMod;
          int x = u + v;
          if (x >= kMod) x -= kMod;
          int y = u - v;
          if (y < 0) y += kMod;
          a[i + j] = x;
          a[i + j + len] = y;
        }
      }
    }

    if (invert) {
      reverse(a.begin() + 1, a.end());
      int inv_n = modpow(n, kMod - 2);
      for (int& z : a) z = z * inv_n % kMod;
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

  vector<int> conv_ntt(vector<int> a, vector<int> b) {
    int need = (int)a.size() + (int)b.size() - 1;

    int n = 1;
    while (n < need) n <<= 1;

    a.resize(n);
    b.resize(n);

    ntt(a, false);
    ntt(b, false);

    for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % kMod;
    ntt(a, true);
    a.resize(need);

    return a;
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  Combinatorics comb(n);
  FFT fft(kMod, G);

  vector<int> a(n + 1, 0), b(n + 1, 0);

  for (int i = 2; i <= n; ++i)
    a[i] = comb.get_fact(i - 2) * ((i - 1) / 2) % kMod;

  for (int j = 0; j <= n; ++j) b[j] = comb.get_inv_fact(j);

  reverse(b.begin(), b.end());
  auto c = fft.conv_ntt(a, b);

  vector<int> ans(n + 1, 0);
  for (int y = 1; y <= n; ++y) ans[y] = comb.get_fact(n - y) * c[n + y] % kMod;

  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << ans[y] << '\n';
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