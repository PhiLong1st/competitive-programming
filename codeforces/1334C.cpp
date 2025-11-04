/*
    Code by: KoKoDuDu
    Created: 2025.11.04 14:26:25
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

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

  vector<int> pre(n);
  pre[0] = a[0];
  for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + max(0LL, a[i] - b[i - 1]);

  vector<int> suf(n);
  suf[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suf[i] = a[i] + suf[i + 1] - a[i + 1] + max(0LL, a[i + 1] - b[i]);
  }

  // dbg(pre);
  // dbg(suf);

  int ans = suf[0];
  for (int i = 1; i < n; ++i) {
    int x = suf[i], y = pre[i - 1] - a[0] + max(0LL, a[0] - b[n - 1]);
    ans = min(ans, x + y);
    // dbg(i, x, y, ans);
  }

  cout << ans << '\n';
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

// 7 2 5