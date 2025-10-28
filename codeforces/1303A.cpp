/*
    Code by: KoKoDuDu
    Created: 2025.10.28 08:16:05
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
const int kMod = 1e9 + 7;
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

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  vector<int> prf(n);

  prf[0] = s[0] == '1';
  for (int i = 1; i < n; ++i) prf[i] = prf[i - 1] + (s[i] == '1');

  if (prf[n - 1] == 0) return void(cout << 0 << '\n');

  pii pos = {-1, -1};
  for (int i = 0; i < n; ++i) {
    if (s[i] != '1') continue;

    pos.fi = pos.fi == -1 ? i : pos.fi;
    pos.se = i;
  }

  int cnt_1 = prf[pos.se] - (pos.fi == 0 ? 0 : prf[pos.fi - 1]);
  cout << pos.se - pos.fi + 1 - cnt_1 << '\n';
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