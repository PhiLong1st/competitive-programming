/*
 Code by: Algorillas
 Created: 2026.09.07 20:54:40
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

bool comp(string a, string b) {
  if (sz(a) > sz(b)) return 1;
  if (sz(a) < sz(b)) return 0;
  for (int i = 0; i < sz(a); ++i) {
    if (a[i] == b[i]) continue;
    if (a[i] > b[i])
      return 1;
    else
      return 0;
  }
  return 1;
}

void solve() {
  int n;
  cin >> n;

  string res = to_string(n);
  for (int i = 0, p = 1; i < to_string(n).size(); ++i, p *= 10) {
    if (p >= n) break;
    vector<string> cur = {res, to_string(p) + to_string(n - p),
                          to_string(n - p) + to_string(p)};

    for (auto& c : cur) {
      if (comp(c, res)) res = c;
    }
    dbg(res, to_string(p) + to_string(n - p), to_string(n - p) + to_string(p));
  }
  cout << res << '\n';
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