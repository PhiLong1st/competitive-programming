/*
 Code by: Algorillas
 Created: 2026.09.14 19:33:28
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
  unordered_map<string, bool> mp, app;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    mp[s] = 1;
  }
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    if (!mp[s]) {
      cout << "WRONG\n";
      continue;
    }
    if (app[s]) {
      cout << "REPEAT\n";
      continue;
    }
    app[s] = 1;
    cout << "OK\n";
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