/*
    Code by: KoKoDuDu
    Created: 2025.10.27 23:48:03
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
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  int l = 0, r = 1e9;
  int ans = 0;
  pii best = {-1, -1};
  while (l <= r) {
    int mid = (l + r) >> 1;

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      int state = 0;
      for (int j = 0; j < m; ++j) {
        if (a[i][j] < mid) continue;
        state |= (1LL << j);
      }
      mp[state] = i;
    }

    bool is_found = false;
    for (auto& [state1, idx1] : mp) {
      for (auto& [state2, idx2] : mp) {
        if ((state1 | state2) == (1LL << m) - 1) {
          best = {idx1, idx2};
          is_found = true;
          break;
        }
      }
    }

    if (is_found) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << best.fi + 1 << " " << best.se + 1 << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}