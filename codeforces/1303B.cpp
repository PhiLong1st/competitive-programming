/*
    Code by: KoKoDuDu
    Created: 2025.10.28 10:00:11
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
  int n, g, b;
  cin >> n >> g >> b;

  int ex = (n + 1) / 2;
  int ans = (ex / g) * (g + b);

  if (ex % g == 0) {
    ans -= b;
  } else {
    ans += ex % g;
  }
  cout << max(ans, n) << endl;
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