/*
    Code by: KoKoDuDu
    Created: 2025.11.06 08:51:30
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

const int dr[4] = {0, 0, -1, 1};
const int dc[4] = {-1, 1, 0, 0};

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

// void solve() {
//   int n, m;
//   cin >> n >> m;

//   vector<string> a(n);
//   for (auto& s : a) cin >> s;

//   string str = "YOKOHAMA";
//   int sz = str.size();

//   int ans = 0;

// auto in_bounds = [&](int r, int c) -> bool {
//   return 0 <= r && r < n && 0 <= c && c < m;
// };

//   auto dfs = [&](auto&& dfs, int r, int c, int p) -> void {
//     if (p == sz - 1) {
//       ans++;
//       return;
//     }

//     for (int i = 0; i < 4; ++i) {
//       int nr = r + dr[i];
//       int nc = c + dc[i];
//       int np = p + 1;

//       if (in_bounds(nr, nc) && a[nr][nc] == str[np]) dfs(dfs, nr, nc, np);
//     }
//   };

//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < m; ++j) {
//       if (a[i][j] != 'Y') continue;
//       dfs(dfs, i, j, 0);
//     }
//   }

//   cout << ans;
// }

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> a(n);
  for (auto& s : a) cin >> s;

  auto in_bounds = [&](int r, int c) -> bool {
    return 0 <= r && r < n && 0 <= c && c < m;
  };

  string str = "YOKOHAMA";
  int sz = str.size();

  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(sz)));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != 'Y') continue;
      dp[i][j][0] = 1;
    }
  }

  for (int p = 1; p < sz; ++p) {
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if (a[r][c] != str[p]) {
          dp[r][c][p] = 0;
          continue;
        }

        for (int k = 0; k < 4; ++k) {
          int nr = r + dr[k], nc = c + dc[k];
          if (!in_bounds(nr, nc)) continue;
          dp[r][c][p] += dp[nr][nc][p - 1];
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += dp[i][j][sz - 1];
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