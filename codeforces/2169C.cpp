/*
    Code by: KoKoDuDu
    Created: 2025.11.14 21:48:49
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

  vector<int> a(n + 1), pf(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i <= n; ++i) pf[i] = pf[i - 1] + a[i];

  int sum = pf[n];
  int ans = sum;
  int minn = 0;

  for (int i = 1; i <= n; ++i) {
    int x = pf[i] - i * i - i;
    int y = -pf[i - 1] + i * i - i;
    minn = min(minn, y);
    ans = max(ans, sum - x - minn);
    // dbg(i, x, y);
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