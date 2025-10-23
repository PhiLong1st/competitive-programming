/*
    Code by: KoKoDuDu
    Created: 2025.10.23 10:55:44
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

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  string s;
  cin >> s;

  s = " " + s;

  vector<int> pre(n + 1);
  for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + (s[i] == 'B' ? a[i] : 0);

  for (int i = 1; i <= n; ++i) a[i] += a[i - 1];

  int res = pre[n];
  for (int i = 1; i <= n; ++i) {
    int alice = a[i] - pre[i];
    res = max({res, alice + pre[n] - pre[i - 1]});
    // dbg(a[i], alice, pre[n] - pre[i - 1]);
  }

  for (int i = n; i >= 1; --i) {
    int alice = a[n] - a[i - 1] - pre[n] + pre[i - 1];
    res = max({res, alice + pre[i - 1]});
  }

  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}