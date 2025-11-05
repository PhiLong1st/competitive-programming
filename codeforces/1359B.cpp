/*
    Code by: KoKoDuDu
    Created: 2025.11.05 10:00:35
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;

  vector<string> a(n);
  for (auto& s : a) cin >> s;

  int cnt = 0;
  for (auto& s : a) {
    for (auto& c : s) {
      cnt += c == '.';
    }
  }

  if (2 * x <= y) return void(cout << cnt * x << '\n');

  int ans = 0;
  for (auto& s : a) {
    for (int i = 1; i < m; ++i) {
      if (s[i] == '*') continue;
      if (s[i] == s[i - 1]) {
        ans += y;
        s[i] = '*', s[i - 1] = '*';
      }
    }

    for (int i = 0; i < m; ++i) {
      if (s[i] == '*') continue;
      ans += x;
      s[i] = '*';
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}