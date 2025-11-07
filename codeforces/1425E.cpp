/*
    Code by: KoKoDuDu
    Created: 2025.11.06 23:56:16
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
  int n, k;
  cin >> n >> k;

  vector<int> a(n + 1), d(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> d[i];

  vector<int> pf(n + 1);
  for (int i = 1; i <= n; i++) pf[i] = pf[i - 1] + a[i];

  int ans = 0;
  if (k == 0)
    for (int i = 1; i <= n; ++i) ans = max(ans, pf[n] - pf[i - 1] - d[i]);

  if (k >= 1) {
    for (int i = 1; i <= n - 1; ++i) {
      int bonus = max(0LL, a[i + 1] - d[i + 1]);
      ans = max(ans, pf[i] - d[1] + pf[n] - pf[i + 1] + bonus);
    }

    for (int i = 1; i <= n - 1; ++i) ans = max(ans, pf[n - 1] - d[i]);

    vector<int> mxR(n + 1);
    mxR[n] = max(0LL, a[n] - d[n]);
    for (int i = n - 1; i >= 1; --i)
      mxR[i] = max(mxR[i + 1], pf[n] - pf[i - 1] - d[i]);

    vector<int> mxL(n + 1);
    int minn = kMaxInf;
    for (int i = 1; i <= n; ++i) {
      minn = min(minn, d[i]);
      mxL[i] = max(mxL[i - 1], pf[i] - minn);
    }

    for (int i = 1; i < n; ++i) ans = max(ans, mxL[i] + mxR[i + 1]);
  }

  if (k >= 2)
    for (int i = 1; i < n; ++i) ans = max(ans, pf[n] - d[i]);

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}