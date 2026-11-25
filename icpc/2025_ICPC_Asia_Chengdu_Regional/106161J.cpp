/*
 Code by: Algorillas
 Created: 2026.09.23 19:52:37
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
  int n, m, k, b;
  cin >> n >> m >> k >> b;
  vector<vector<int>> votes(n, vector<int>(m));
  vector<int> fails;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int score = 0;
    for (int j = 0; j < m; ++j) cin >> votes[i][j], score += votes[i][j];
    if (score < k)
      fails.push_back(i);
    else
      res++;
  }

  for (auto p : fails) {
    if (b == 0) break;
    for (int i = 0; i < m; ++i) {
      votes[p][i] = (votes[p][i] > 0 ? votes[p][i] - 1 : votes[p][i] + 1);
    }
    int score = 0;
    for (int i = 0; i < m; ++i) score += votes[p][i];
    if (score >= k) {
      b--;
      res++;
    }
  }
  cout << res << '\n';
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