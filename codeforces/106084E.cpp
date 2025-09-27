/*
    Code by: KoKoDuDu
    Created: 2025.09.27 15:51:27
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> a(n + 1, vector<int>(m + 1)),
      grid(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= k; ++i) {
    int x, y;
    cin >> x >> y;
    a[x][y] = i;
  }

  int need = 0, mx = 0;

  int u1, v1, u2, v2;
  cin >> u1 >> v1 >> u2 >> v2;
  for (int i = u1; i <= u2; ++i) {
    for (int j = v1; j <= v2; ++j) {
      need += a[i][j] != 0;
      mx = max(mx, a[i][j]);
    }
  }

  if (need == 0) {
    return void(cout << 0);
  }

  auto get_valid_cells = [&](int max_val) {
    int num_cell = 0;
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, 1, -1, 0};

    queue<pair<int, int>> que;
    vector<vector<int>> seen(n + 1, vector<int>(m + 1));
    vector<vector<bool>> remove(n + 1, vector<bool>(m + 1));

    for (int i = u1; i <= u2; ++i) {
      for (int j = v1; j <= v2; ++j) {
        que.push({i, j});
        seen[i][j] = true;
        remove[i][j] = true;
      }
    }

    auto is_in_grid = [&](int r, int c) {
      return 0 < r && r <= n && 0 < c && c <= m;
    };

    while (!que.empty()) {
      auto [r, c] = que.front();
      que.pop();

      for (int i = 0; i < 4; ++i) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (!is_in_grid(nr, nc)) {
          continue;
        }

        if (seen[nr][nc]) {
          continue;
        }

        if (a[nr][nc] > max_val) {
          continue;
        }
        num_cell += a[nr][nc] == 0 && !remove[nr][nc];
        seen[nr][nc] = true;
        que.push({nr, nc});
      }
    }

    return num_cell;
  };

  int ans = kInf;

  int l = mx, r = 1e10;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (get_valid_cells(mid) >= need) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ((ans == kInf) ? -1 : ans);
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