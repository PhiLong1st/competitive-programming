/*
    Code by: KoKoDuDu
    Created: 2025.08.04 14:07:28
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;
const int INF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> cntTwo(n, vector<int>(n)), cntFive(n, vector<int>(n));
  vector<vector<int>> dpTwo(n, vector<int>(n, INF)), dpFive(n, vector<int>(n, INF));
  vector<vector<pll>> traceTwo(n, vector<pll>(n, { -1, -1 })), traceFive(n, vector<pll>(n, { -1, -1 }));

  bool isAppearZero = false;
  int posX = -1, posY = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if (x == 0) {
        isAppearZero = true;
        posX = i;
        posY = j;
        x = 10;
      }

      while (x % 2 == 0) {
        cntTwo[i][j]++;
        x /= 2;
      }

      while (x % 5 == 0) {
        cntFive[i][j]++;
        x /= 5;
      }
    }
  }

  dpTwo[0][0] = cntTwo[0][0];
  dpFive[0][0] = cntFive[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (i > 0) {
        if (dpTwo[i][j] > dpTwo[i - 1][j] + cntTwo[i][j]) {
          dpTwo[i][j] = dpTwo[i - 1][j] + cntTwo[i][j];
          traceTwo[i][j] = { i - 1, j };
        }

        if (dpFive[i][j] > dpFive[i - 1][j] + cntFive[i][j]) {
          dpFive[i][j] = dpFive[i - 1][j] + cntFive[i][j];
          traceFive[i][j] = { i - 1, j };
        }
      }

      if (j > 0) {
        if (dpTwo[i][j] > dpTwo[i][j - 1] + cntTwo[i][j]) {
          dpTwo[i][j] = dpTwo[i][j - 1] + cntTwo[i][j];
          traceTwo[i][j] = { i, j - 1 };
        }

        if (dpFive[i][j] > dpFive[i][j - 1] + cntFive[i][j]) {
          dpFive[i][j] = dpFive[i][j - 1] + cntFive[i][j];
          traceFive[i][j] = { i, j - 1 };
        }
      }
    }
  }

  if (min(dpTwo[n - 1][n - 1], dpFive[n - 1][n - 1]) != 0 && isAppearZero) {
    cout << "1\n";
    for (int i = 0; i < posX; i++) {
      cout << "D";
    }
    for (int i = 0; i < posY; i++) {
      cout << "R";
    }
    for (int i = posY; i < n - 1; i++) {
      cout << "R";
    }
    for (int i = posX; i < n - 1; i++) {
      cout << "D";
    }
    return;
  }


  if (dpTwo[n - 1][n - 1] < dpFive[n - 1][n - 1]) {
    cout << dpTwo[n - 1][n - 1] << '\n';
    vector<pll> path;
    int i = n - 1, j = n - 1;
    while (i != -1 && j != -1) {
      path.push_back({ i, j });
      auto [ni, nj] = traceTwo[i][j];
      i = ni;
      j = nj;
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size() - 1; i++) {
      auto [x, y] = path[i];
      auto [nx, ny] = path[i + 1];
      if (x == nx) {
        cout << "R";
      }
      else {
        cout << "D";
      }
    }
    return;
  }

  cout << dpFive[n - 1][n - 1] << '\n';
  vector<pll> path;
  int i = n - 1, j = n - 1;
  while (i != -1 && j != -1) {
    path.push_back({ i, j });
    auto [ni, nj] = traceFive[i][j];
    i = ni;
    j = nj;
  }
  reverse(path.begin(), path.end());

  for (int i = 0; i < path.size() - 1; i++) {
    auto [x, y] = path[i];
    auto [nx, ny] = path[i + 1];
    if (x == nx) {
      cout << "R";
    }
    else {
      cout << "D";
    }
  }
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