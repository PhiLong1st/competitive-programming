/*
    Code by: KoKoDuDu
    Created: 2025.09.27 19:52:51
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n + 1, vector<char>(m + 1));
  vector<vector<bool>> seen(n + 1, vector<bool>(m + 1));
  vector<pair<int, int>> bld;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (a[i][j] != '#') continue;
      bld.emplace_back(i, j);
      seen[i][j] = true;
    }
  }

  auto isOk = [&](int x, int y) -> bool {
    if (a[x][y] == '#') return false;
    int cnt = 0;
    for (int d = 0; d < 4; ++d) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      cnt += (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '#');
    }
    return cnt == 1;
  };

  auto isInBounds = [&](int nx, int ny) -> bool {
    return nx >= 1 && nx <= n && ny >= 1 && ny <= m;
  };

  vector<pair<int, int>> nbld;
  int res = 0;
  for (;; nbld.clear()) {
    res += bld.size();
    for (auto c : bld) {
      int x = c.first, y = c.second;
      for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (isInBounds(nx, ny) && isOk(nx, ny) && !seen[nx][ny]) {
          seen[nx][ny] = 1;
          nbld.push_back({nx, ny});
        }
      }
    }
    if (nbld.empty()) break;
    bld = move(nbld);
    for (auto c : bld) {
      int x = c.first, y = c.second;
      a[x][y] = '#';
    }
  }

  cout << res << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}