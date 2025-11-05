/*
    Code by: KoKoDuDu
    Created: 2025.11.05 23:44:10
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
const int kMaxInf = 1e18;
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& c : a) cin >> c;

  int total = accumulate(a.begin(), a.end(), 0ll);
  int l = 0, r = 0, sum = 0;

  array<int, 3> fn = {kMaxInf, kMaxInf, kMaxInf};

  for (int r = 0; r < n; ++r) {
    sum += a[r];
    while (l < r && sum > total / 2) {
      sum -= a[l];
      ++l;
    }

    fn = min(fn, {abs(total - 2 * sum), total - sum, sum});
  }

  int x = fn[1], y = fn[2];
  if (x > y) swap(x, y);

  int res = 0;

  if (2 * x <= y) {
    res += x;
  } else {
    res += y - x;
    x -= y - x;
    y = x;
    res += (x + y) / 3;
  }

  cout << res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}