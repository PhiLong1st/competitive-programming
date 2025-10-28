/*
    Code by: KoKoDuDu
    Created: 2025.10.28 13:47:33
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
#define el '\n'
using namespace std;

const double PI = acos(-1);
const int kMaxN = 1e6 + 0307;
const int kMod = 998244353;
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

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Combinatorics comb(kMaxN);

  int t = 1;
  cin >> t;
  while (t--) {
    vector<int> a(4);
    for (auto& x : a) cin >> x;

    if (abs(a[0] - a[1]) > 1) {
      cout << 0 << el;
      continue;
    }

    if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) {
      cout << 1 << el;
      continue;
    }

    int ans = 0;
    int s1 = 0, s2 = 0;
    int n = a[0] + a[1];

    if (a[0] != a[1]) {
      s1 = (a[2] == 0), s2 = (a[3] == 0);
      for (int x = 1; x <= a[2]; ++x) {
        int num_sol = comb.get_nCk(a[2] - 1, x - 1);
        int cnt = comb.get_nCk(n / 2 + 1, x);
        s1 += num_sol * cnt % kMod;
        s1 %= kMod;
      }

      for (int x = 1; x <= a[3]; ++x) {
        int num_sol = comb.get_nCk(a[3] - 1, x - 1);
        s2 += num_sol * comb.get_nCk(n / 2 + 1, x) % kMod;
        s2 %= kMod;
      }

      ans += (s1 * s2) % kMod;
      ans %= kMod;
    } else {
      // 12
      s1 = (a[2] == 0), s2 = (a[3] == 0);
      for (int x = 1; x <= a[2]; ++x) {
        int num_sol = comb.get_nCk(a[2] - 1, x - 1);
        int cnt = comb.get_nCk(n / 2, x);
        s1 += num_sol * cnt % kMod;
        s1 %= kMod;
      }

      for (int x = 1; x <= a[3]; ++x) {
        int num_sol = comb.get_nCk(a[3] - 1, x - 1);
        s2 += num_sol * comb.get_nCk(n / 2 + 1, x) % kMod;
        s2 %= kMod;
      }

      ans += (s1 * s2) % kMod;
      ans %= kMod;

      // 21
      s1 = (a[2] == 0), s2 = (a[3] == 0);
      for (int x = 1; x <= a[2]; ++x) {
        int num_sol = comb.get_nCk(a[2] - 1, x - 1);
        int cnt = comb.get_nCk(n / 2 + 1, x);
        s1 += num_sol * cnt % kMod;
        s1 %= kMod;
      }

      for (int x = 1; x <= a[3]; ++x) {
        int num_sol = comb.get_nCk(a[3] - 1, x - 1);
        s2 += num_sol * comb.get_nCk(n / 2, x) % kMod;
        s2 %= kMod;
      }

      ans += (s1 * s2) % kMod;
      ans %= kMod;
    }
    cout << ans << "\n";
  }
  return 0;
}