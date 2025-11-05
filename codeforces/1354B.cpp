/*
    Code by: KoKoDuDu
    Created: 2025.11.04 22:16:35
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
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  s = " " + s;

  int ans = kMaxInf;
  map<char, int> mp;
  int l = 1, r = 1, cnt = 0;
  while (r <= n) {
    while (r <= n && cnt < 3) {
      if (mp[s[r]] == 0) cnt++;
      mp[s[r]]++;
      ++r;
    }

    while (l <= r && cnt == 3) {
      ans = min(ans, r - l);
      mp[s[l]]--;
      if (mp[s[l]] == 0) cnt--;
      ++l;
    }
  }

  cout << (ans == kMaxInf ? 0 : ans) << '\n';
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