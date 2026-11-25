/*
 Code by: Algorillas
 Created: 2026.09.05 20:34:41
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
  int l, r;
  cin >> l >> r;

  if (l == r || r == l - 2) {
    cout << (l + r) + (l + r) / 2;
  } else if (r == l - 1) {
    cout << l + r;
  } else {
    cout << (l + r) * 2;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}