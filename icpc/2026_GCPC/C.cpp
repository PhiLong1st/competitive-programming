/*
 Code by: Algorillas
 Created: 2026.11.09 20:48:37
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

void solve() {
  int r = 59, c = 42;

  cout << r / 2 << ' ' << c / 2 << '\n';
  cout.flush();

  map<pair<int, int>, int> mp;
  int x, y;
  cin >> x >> y;

  mp[{x, y}] = 1;

  for (int dir = 0; dir < 4; ++dir) {
    int nx = r / 2 + dx[dir];
    int ny = c / 2 + dy[dir];

    if (mp[{nx, ny}] || mp[{nx + dx[dir], ny + dy[dir]}] ||
        mp[{nx - 2 * dx[dir], ny - 2 * dy[dir]}])
      continue;

    cout << nx << ' ' << ny << '\n';
    cout.flush();

    cin >> x >> y;
    mp[{x, y}] = 1;

    int fx = nx + dx[dir];
    int fy = ny + dy[dir];

    if (mp[{fx, fy}]) {
      fx = nx + 2 * dx[(dir + 2) % 4];
      fy = ny + 2 * dy[(dir + 2) % 4];
    }

    cout << fx << ' ' << fy << '\n';
    cout.flush();

    break;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}