/*
 Code by: Algorillas
 Created: 2026.09.03 21:08:04
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
  int n, a, b;
  cin >> n >> a >> b;
  auto bs = bitset<100>(n);
  int cnt = 0, cnt0 = 0;

  if (a != b) return void(cout << "NO\n");

  set<int> uni;
  for (int i = 1; i < 99; ++i) {
    if (bs[i - 1] != bs[i] && bs[i] != bs[i + 1]) {
      uni.insert(bs[i]);
    }
  }
  if (bs[0] != bs[1] && bs[0]) uni.insert(bs[0]);
  if (bs[99] != bs[98] && bs[99]) uni.insert(bs[99]);
  dbg(bs);
  dbg(uni);
  cout << (uni.size() != 2 ? "YES\n" : "NO\n");
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