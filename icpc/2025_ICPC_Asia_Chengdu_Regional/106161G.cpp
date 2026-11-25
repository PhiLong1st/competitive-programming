/*
 Code by: Algorillas
 Created: 2026.09.23 19:58:16
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
  int n, k, m;
  cin >> n >> k >> m;

  int t = n / k;
  int rest = n - t;

  int x = min(m, rest);

  m -= x;
  t -= m;

  cout << m + x + (t + 1) / 2 << '\n';
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