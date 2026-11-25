/*
 Code by: Algorillas
 Created: 2026.09.07 21:23:51
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

struct FenwickTree2D {
  vector<vector<long long>> bit;
  int n, m;

  FenwickTree2D(int _n, int _m) {
    n = _n;
    m = _m;
    bit.assign(n + 1, vector<long long>(m + 1, 0));
  }

  void update(int x, int y, long long delta) {
    for (int i = x; i <= n; i += i & -i) {
      for (int j = y; j <= m; j += j & -j) {
        bit[i][j] += delta;
      }
    }
  }

  long long sum(int x, int y) {
    long long ret = 0;
    for (int i = x; i > 0; i -= i & -i) {  // i -= i & -i
      for (int j = y; j > 0; j -= j & -j) {
        ret += bit[i][j];
      }
    }
    return ret;
  }

  long long query(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) +
           sum(x1 - 1, y1 - 1);
  }
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char x;
      cin >> x;
      a[i][j] = (x == '#');
    }
  }
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