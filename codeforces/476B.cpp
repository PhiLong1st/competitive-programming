/*
    Code by: KoKoDuDu
    Created: 2025.10.27 17:27:54
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
  string s1, s2;
  cin >> s1 >> s2;

  int plus_s1 = 0, minus_s1 = 0;
  for (char c : s1) {
    plus_s1 += c == '+';
    minus_s1 += c == '-';
  }

  int plus_s2 = 0, minus_s2 = 0;
  int quest_s2 = 0;
  for (char c : s2) {
    plus_s2 += c == '+';
    minus_s2 += c == '-';
    quest_s2 += c == '?';
  }

  if (quest_s2 == 0) {
    cout << fixed << setprecision(12)
         << 1.0 * (plus_s1 == plus_s2 && minus_s1 == minus_s2) << el;
    return;
  }

  int need_plus = plus_s1 - plus_s2;
  int need_minus = minus_s1 - minus_s2;

  if (need_plus < 0 || need_minus < 0 || need_plus + need_minus != quest_s2) {
    cout << fixed << setprecision(12) << 0.0 << el;
    return;
  }

  Combinatorics comb(quest_s2);
  int ways = comb.get_fact(quest_s2) /
             (comb.get_fact(need_plus) * comb.get_fact(need_minus));
  int total_ways = 1LL << quest_s2;
  cout << fixed << setprecision(12) << 1.0 * ways / total_ways << el;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}