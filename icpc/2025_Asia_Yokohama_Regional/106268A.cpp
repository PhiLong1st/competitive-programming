/*
 Code by: Algorillas
 Created: 2026.09.07 21:54:11
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
  int n, len;
  cin >> n >> len;
  vector<array<int, 2>> pos(n);  // col - row
  for (int i = 0; i < n; i++) cin >> pos[i][1] >> pos[i][0];
  if (n % 2 == 1) {
    cout << "no\n";
    return;
  }
  sort(pos.begin(), pos.end());
  int left = 0, right = len;
  int res = 0;
  for (int i = 0; i < n; i += 2) {
    auto p1 = pos[i];
    auto p2 = pos[i + 1];
    if (p2[0] - p1[0] > 2) {
      cout << "no\n";
      return;
    }
    if (p1[0] == p2[0]) {
      left = p1[0];
      continue;
    }

    if (p1[0] + 1 == p2[0]) {
      if (i == n - 2) {
        res += (p1[1] != p2[1]);
        break;
      }
      auto p3 = pos[i + 2];
      if (p3[0] == p2[0]) {
        if (p2[1] == p1[1]) swap(p3, p2);
        res++;
      } else {
        res += (p1[1] != p2[1]);
      }
    }

    if (p1[0] + 2 == p2[0]) {
      // cout << res << "\n";
      // cout << p1[0] << " " << p1[1] << "\n";
      // cout << p2[0] << " " << p2[1] << "\n";
      res += (p1[1] == p2[1] ? 1 : 2);
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