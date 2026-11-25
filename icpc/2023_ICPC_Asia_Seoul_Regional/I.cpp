/*
 Code by: Algorillas
 Created: 2026.09.17 21:09:40
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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  if (n == 1) {
    cout << 1;
    return;
  }
  int res = 1;
  int line = a[n - 1].second;
  for (int i = n - 2; i >= 0; i--) {
    int top = a[i].second;
    int bot = a[i].first;

    if (line < bot) {
      res++;
      line = top;
    } else {
      line = min(line, top);
    }
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