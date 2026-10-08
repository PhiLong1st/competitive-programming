/*
 Code by: Algorillas
 Created: 2026.09.17 21:03:21
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const int PR[4] = {2, 3, 5, 7};
// exponent of 2, 3, 5, 7 in digits 1..9
const int EXP[10][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0},
                        {2, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1},
                        {3, 0, 0, 0}, {0, 2, 0, 0}};

int c[4];       // exponent of 2, 3, 5, 7 in k
int mul[4];     // mixed radix multipliers
int total;      // number of deficit states
vector<vector<int>> g;  // g[rem][state]: sequences of rem digits (1..9) that
                        // cover the remaining deficit `state`
ll pw9[30], pw10[30];

// state = (d2, d3, d5, d7) remaining deficits, encoded in mixed radix
int enc(const int d[4]) {
  int s = 0;
  for (int i = 0; i < 4; ++i) s += d[i] * mul[i];
  return s;
}

int apply(int s, int dg) {
  int d[4];
  for (int i = 0; i < 4; ++i) {
    d[i] = (s / mul[i]) % (c[i] + 1);
    d[i] = max(0, d[i] - EXP[dg][i]);
  }
  return enc(d);
}

// number of special numbers in [1, X] (X given as decimal string) mod p
ll calc(const string& x) {
  int n = x.size();
  ll xmod = 0;
  for (char ch : x) xmod = (xmod * 10 + (ch - '0')) % MOD;

  ll zeroFree = 0;         // zero-free numbers in [1, X]
  ll specialZeroFree = 0;  // zero-free and k-special numbers in [1, X]

  // numbers shorter than n
  for (int m = 1; m < n; ++m) {
    zeroFree = (zeroFree + pw9[m]) % MOD;
    specialZeroFree = (specialZeroFree + g[m][enc(c)]) % MOD;
  }

  // numbers with exactly n digits, walk along X
  int full[4] = {c[0], c[1], c[2], c[3]};
  int s = enc(full);
  bool ok = true;
  for (int i = 0; i < n && ok; ++i) {
    int xi = x[i] - '0';
    int rem = n - i - 1;
    for (int d = 1; d < xi; ++d) {
      zeroFree = (zeroFree + pw9[rem]) % MOD;
      specialZeroFree = (specialZeroFree + g[rem][apply(s, d)]) % MOD;
    }
    if (xi == 0) {
      ok = false;
      break;
    }
    s = apply(s, xi);
  }
  if (ok) {
    zeroFree = (zeroFree + 1) % MOD;
    if (s == 0 && g[0][0]) specialZeroFree = (specialZeroFree + 1) % MOD;
  }

  // numbers containing a zero digit have product 0 -> always special
  return ((xmod - zeroFree + specialZeroFree) % MOD + MOD) % MOD;
}

bool isSpecial(const string& x) {
  int d[4] = {c[0], c[1], c[2], c[3]};
  int s = enc(d);
  for (char ch : x) {
    int dg = ch - '0';
    if (dg == 0) return true;
    s = apply(s, dg);
  }
  return s == 0 && g[0][0];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  ll k;
  string L, R;
  cin >> k >> L >> R;

  for (int i = 0; i < 4; ++i) {
    c[i] = 0;
    while (k % PR[i] == 0) {
      k /= PR[i];
      c[i]++;
    }
  }
  // if k still has a prime factor > 7, only numbers containing a 0 digit work
  bool impossible = (k != 1);

  mul[0] = 1;
  for (int i = 1; i < 4; ++i) mul[i] = mul[i - 1] * (c[i - 1] + 1);
  total = mul[3] * (c[3] + 1);

  pw9[0] = pw10[0] = 1;
  for (int i = 1; i < 30; ++i) {
    pw9[i] = pw9[i - 1] * 9 % MOD;
    pw10[i] = pw10[i - 1] * 10 % MOD;
  }

  int maxLen = max(L.size(), R.size());
  g.assign(maxLen + 1, vector<int>(total, 0));
  g[0][0] = impossible ? 0 : 1;
  for (int r = 1; r <= maxLen; ++r)
    for (int s = 0; s < total; ++s) {
      ll v = 0;
      for (int dg = 1; dg <= 9; ++dg) v += g[r - 1][apply(s, dg)];
      g[r][s] = v % MOD;
    }

  bool spL = impossible ? (L.find('0') != string::npos) : isSpecial(L);
  ll ans = calc(R) - calc(L) + (spL ? 1 : 0);
  ans = (ans % MOD + MOD) % MOD;
  cout << ans << "\n";
  return 0;
}
