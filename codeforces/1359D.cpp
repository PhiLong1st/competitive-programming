/*
    Code by: KoKoDuDu
    Created: 2025.11.05 15:39:37
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

// void solve() {
//   int n;
//   cin >> n;

//   vector<int> a(n);
//   for (auto& x : a) cin >> x;

//   int ans = 0;
//   for (int j = 1; j <= 30; ++j) {
//     int cur = 0;
//     for (int i = 0; i < n; ++i) {
//       if (a[i] > j) {
//         cur = 0;
//       } else {
//         cur = max(cur + a[i], 0LL);
//         ans = max(ans, cur - j);
//       }
//     }
//   }
//   cout << ans;
// }

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& x : a) cin >> x;

  int ans = 0;
  int pref = 0;

  vector<pii> save;
  for (int i = 0; i < n; ++i) {
    pref += a[i];

    for (auto& [x, y] : save) x = max(x, a[i]);
    save.emplace_back(a[i], pref - a[i]);

    sort(save.begin(), save.end());

    map<int, int> mp;
    for (auto& [x, y] : save) {
      if (!mp.count(x)) mp[x] = y;
      mp[x] = min(mp[x], y);
    }

    save.clear();
    for (auto& [x, y] : mp) {
      save.emplace_back(x, y);
      ans = max(ans, pref - x - y);
    }
  }

  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}