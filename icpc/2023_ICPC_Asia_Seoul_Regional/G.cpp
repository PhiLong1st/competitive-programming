/*
 Code by: Algorillas
 Created: 2026.09.17 21:33:46
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
  int n, k, m, f;
  cin >> n >> k >> m >> f;
  vector<vector<int>> a(k, vector<int>(m));
  unordered_map<int, bitset<101>> pos;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      pos[a[i][j]][i] = 1;
    }
  }
  unordered_map<bitset<101>, vector<int>> patterns;
  for (int i = 1; i <= n; ++i) {
    patterns[pos[i]].push_back(i);
  }
  int only_ans = 0, cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!pos[i].count()) {
      only_ans = i;
      cnt++;
    }
  }
  if (cnt != 1) only_ans = 0;
  set<int> res;

  for (int _ = 0; _ < f; ++_) {
    string s;
    cin >> s;
    int is_has = 0;
    bitset<101> fn;
    int valid_idx = -1;
    for (int i = 0; i < sz(s); ++i) {
      char c = s[i];
      fn[i] = (c == 'Y' ? 1 : 0);
      if (c == 'Y' && !is_has) {
        is_has = true;
        valid_idx = i;
      }
    }
    if (valid_idx != -1) {
      if (patterns[fn].size() != 1) {
        cout << "0\n";
        continue;
      }
      cout << (patterns[fn].back()) << '\n';
    } else {
      cout << only_ans << '\n';
    }
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