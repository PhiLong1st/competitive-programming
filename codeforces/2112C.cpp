/*
    Code by: KoKoDuDu
    Created: 2025.11.13 21:47:06
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

  vector<int> a(n);
  for (auto& x : a) cin >> x;

  sort(a.begin(), a.end());

  int maxx = *max_element(a.begin(), a.end());
  int ans = 0;

  // for (int i = 0; i < n; ++i) {
  //   for (int j = i + 1; j < n; ++j) {
  //     for (int k = j + 1; k < n; k++) {
  //       int x = a[i], y = a[j], z = a[k];
  //       ans += ((x + y + z) > maxx) && ((x + y) > z);
  //     }
  //   }
  // }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x = a[i], y = a[j];
      int l = maxx - x - y, r = x + y;

      if (maxx - x - y >= x + y) continue;
      int l_pos = upper_bound(a.begin() + j, a.end(), maxx - x - y) - a.begin();
      int r_pos = lower_bound(a.begin() + j, a.end(), x + y) - a.begin() - 1;

      l_pos = max(j + 1, l_pos);
      if (l_pos > r_pos) continue;
      ans += r_pos - l_pos + 1;
    }
  }

  cout << ans << '\n';
}

// x < y < z  -  t != (x, y, z)
// x + y > maxx - z -> z > maxx - x - y
// x + y > z

//  maxx - x - y < z < x + y

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}