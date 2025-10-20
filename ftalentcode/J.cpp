/*
    Code by: KoKoDuDu
    Created: 2025.10.19 08:50:37
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
  int n;
  cin >> n;

  vector<pair<string, int>> a(n);
  for (int i = 0; i < n; ++i) {
    string s;
    int t;
    cin >> s >> t;

    a[i].fi = s, a[i].se = t;
  }

  // for (auto& s : a) cout << s.fi << ' ' << s.se << '\n';
  auto cmp = [&](pair<string, int> x, pair<string, int> y) -> bool {
    string s1 = x.first, s2 = y.first;
    for (auto& c : s1) {
      if (c < 97) c += 32;
      c = (char)c;
    }
    for (auto& c : s2) {
      if (c < 97) c += 32;
      c = (char)c;
    }

    // dbg(s1, s2);

    if (s1 == s2) return x.se < y.se;
    return s1 < s2;
  };

  sort(a.begin(), a.end(), cmp);
  for (auto& c : a) cout << c.fi << ' ' << c.se << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}