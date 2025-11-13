/*
    Code by: KoKoDuDu
    Created: 2025.11.13 23:54:21
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

int binpow(int a, int k, int mod) {
  int res = 1;
  for (; k; k >>= 1, a = a * a % mod) {
    if (k & 1) res = res * a % mod;
  }
  return res;
}

int discrete_log(int a, int b, int m) {
  a %= m, b %= m;
  int n = sqrt(m) + 1;

  int k = 1, add = 0, g;
  while ((g = __gcd(a, m)) > 1) {
    if (b == k) return add;
    if (b % g) return -1;
    b /= g, m /= g, ++add;
    a %= m;
    k = (k * a / g) % m;
  }

  unordered_map<int, int> vals;
  for (int q = 0, cur = b; q <= n; ++q) {
    vals[cur] = q;
    cur = cur * a % m;
  }

  int step = binpow(a, n, m);
  for (int p = 1, f1 = k; p <= n; p++) {
    f1 = f1 * step % m;
    if (vals.count(f1)) {
      int ans = n * p - vals[f1] + add;
      return ans;
    }
  }
  return -1;
}

void solve() {
  int a, b, s, p, v;
  cin >> a >> b >> s >> p >> v;

  if (a == 1) {
    int t = (v - s + p) % p;
    cout << t * binpow(b, p - 2, p) % p << '\n';
    return;
  }

  int z1 = ((a - 1) * v % p + b) % p;
  int z2 = ((a - 1) * s % p + b) % p;
  int z = z1 * binpow(z2, p - 2, p) % p;

  if (z2 == 0) return void(cout << (s == v ? "0\n" : "IMPOSSIBLE\n"));

  int n = discrete_log(a, z, p);
  if (n == -1) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << n << '\n';
  }
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