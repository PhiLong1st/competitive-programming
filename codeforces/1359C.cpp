/*
    Code by: KoKoDuDu
    Created: 2025.11.05 10:10:12
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
  int h, c, t;
  cin >> h >> c >> t;

  int d = 2 * t - h - c;
  if (d <= 0) return void(cout << 2 << '\n');

  auto num = [&](int k) -> int {
    int v = (t - c) - k * d;
    return v >= 0 ? v : -v;
  };

  auto den = [&](int k) -> int { return 2 * k - 1; };

  int x = (t - c) / d;
  int l = num(x) * den(x + 1);
  int r = num(x + 1) * den(x);
  cout << ((l <= r) ? den(x) : den(x + 1)) << '\n';
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
