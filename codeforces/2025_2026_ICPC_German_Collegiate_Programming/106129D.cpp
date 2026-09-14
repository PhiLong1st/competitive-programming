/*
 Code by: Algorillas
 Created: 2026.09.05 16:56:21
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
  int n;
  cin >> n;
  pair<int, int> tl = {INF, -1}, br = {-1, INF};
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    tl.first = min(tl.first, x);
    tl.second = max(tl.second, y);
    br.first = max(br.first, x);
    br.second = min(br.second, y);
  }
  cout << "4\n";
  cout << tl.first << " " << tl.second << '\n';
  cout << tl.first << " " << br.second << '\n';
  cout << br.first << " " << br.second << '\n';
  cout << br.first << " " << tl.second << '\n';
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