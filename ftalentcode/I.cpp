/*
    Code by: KoKoDuDu
    Created: 2025.10.19 10:08:08
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
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i)
    if (0 > a[i] || a[i] >= i) return void(cout << -1);

  vector<int> ans(n + 1);
  for (int i = n; i >= 1; --i) {
    int pos = 0, cnt = 0;
    while (pos <= n && cnt <= a[i]) {
      ++pos;
      cnt += ans[pos] == 0;
    }

    ans[pos] = i;
    // dbg(i, pos);
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}