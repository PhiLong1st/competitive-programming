/*
    Code by: KoKoDuDu
    Created: 2025.09.19 22:56:11
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  int res = 0;
  for (int j = 0; j < m; ++j) {
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
      maxx = max(maxx, a[i][j]);
    }
    res += maxx;
  }
  cout << res;
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