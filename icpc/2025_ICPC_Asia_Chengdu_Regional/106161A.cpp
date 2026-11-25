/*
Code by: Algorillas
Created: 2026.09.23 22:21:53
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), l(n), r(n), res(n);
  for (auto& c : a) cin >> c;

  for (int m = max(1ll, 100 - n); m <= n + 10000; ++m) {
    for (int i = 0; i < n; ++i) {
      int x = a[i];
      if (x == 0) {
        l[i] = 0;
        r[i] = 0.4 * m / 100.0;
      } else {
        l[i] = ceil((1.0 * (x - 1.0) + 0.5) * m / 100.0);
        r[i] = floor((1.0 * min(100.0, (x + 1.0) + 0.4)) * m / 100.0);
      }
    }

    int left = 0, right = 0;
    for (int i = 0; i < n; ++i) {
      left += l[i];
      right += r[i];
    }

    if (left <= m && m <= right) {
      int total = left;
      for (int i = 0; i < n; ++i) {
        int cur = l[i];
        while (cur < r[i] && total < m) {
          total++;
          cur++;
        }
        res[i] = cur;
      }

      // cerr << m << '\n';
      // for (int i = 0; i < n; ++i) cout << l[i] << ' ' << r[i] << '\n';

      // bool isValid = true;
      // for (int i = 0; i < n; ++i) {
      //   int val = (ceil(1.0 * res[i] / m * 100.0) / 100.0) * 100;
      //   // cout << val << ' ';
      //   if (val != a[i]) {
      //     isValid = false;
      //     break;
      //   }
      // }

      // if (!isValid) continue;

      cout << "Yes\n";
      for (int i = 0; i < n; ++i) cout << res[i] << ' ';
      cout << "\n";

      return;
    }
  }

  cout << "No\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}