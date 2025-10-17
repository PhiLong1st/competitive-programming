/*
    Code by: KoKoDuDu
    Created: 2025.10.17 18:43:16
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

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

void solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n), pref(n), val(n);
  for (auto& c : a) cin >> c;

  pref[0] = a[0] % kMod;
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + a[i];
    pref[i] %= kMod;
  }

  val[0] = a[0] * pref[0] % kMod;
  for (int i = 1; i < n; ++i) {
    val[i] = val[i - 1] + a[i] * pref[i] % kMod;
    val[i] %= kMod;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;

    int sum = (l == 0 ? pref[r] : (pref[r] - pref[l - 1] + kMod)) % kMod;
    int val_sum = (l == 0 ? val[r] : (val[r] - val[l - 1] + kMod)) % kMod;

    cout << (pref[r] * sum % kMod - val_sum + kMod) % kMod << '\n';
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