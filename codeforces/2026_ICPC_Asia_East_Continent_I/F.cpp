/*
 Code by: Algorillas
 Created: 2026.09.14 19:36:28
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto& d : a)
    for (auto& c : d) cin >> c;
  int prev = 0, res = 0;
  for (int i = 0; i < n; ++i) {
    int score = 0;
    for (int j = 0; j < m; ++j) score += a[i][j];
    res += score < prev;
    prev = score;
  }
  cout << res;
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