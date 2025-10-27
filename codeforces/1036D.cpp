/*
    Code by: KoKoDuDu
    Created: 2025.10.27 08:20:13
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
  int n, m;

  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;

  cin >> m;
  vector<int> b(m);
  for (auto& x : b) cin >> x;

  int sum_a = accumulate(a.begin(), a.end(), 0LL);
  int sum_b = accumulate(b.begin(), b.end(), 0LL);

  if (sum_a != sum_b) return void(cout << -1 << '\n');

  int ans = 0;
  for (int i = 0; i < n; ++i) a[i] += (i != 0) ? a[i - 1] : 0;
  for (int i = 0; i < m; ++i) b[i] += (i != 0) ? b[i - 1] : 0;

  int pos_a = 0, pos_b = 0;
  for (int i = 0; i < n; ++i) {
    int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    if (b[pos] == a[i]) ans++;
  }

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