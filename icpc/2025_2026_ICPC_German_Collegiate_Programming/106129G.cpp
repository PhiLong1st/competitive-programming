/*
 Code by: Algorillas
 Created: 2026.09.05 16:30:08
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
  string password = "aA9!#$%^()+,";
  int cnt = 0;
  while (cnt++ < n && next_permutation(all(password))) {
    cout << password << '\n';
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