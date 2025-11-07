/*
    Code by: KoKoDuDu
    Created: 2025.11.06 11:18:54
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
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, kMaxInf));
  vector<vector<pii>> save(n + 1, vector<pii>(n + 1));

  auto is_valid = [&](string s1, string s2) -> bool {
    int n1 = s1.size(), n2 = s2.size();
    if (n1 % n2 != 0) return false;

    int pos = 0;
    for (int i = 0; i < n1; ++i) {
      if (s1[i] != s2[pos]) return false;
      pos = (pos + 1) % n2;
    }
    return true;
  };

  auto trace = [&](auto&& trace, int l, int r) -> string {
    auto [type, mid] = save[l][r];

    if (type == 0) return s.substr(l, r - l + 1);

    if (type == 1) return trace(trace, l, mid) + trace(trace, mid + 1, r);

    string str = trace(trace, l, mid);
    int sz1 = r - l + 1, sz2 = mid - l + 1;
    int mul = sz1 / sz2;
    return mul == 1 ? str : to_string(mul) + "(" + str + ")";
  };

  s = " " + s;
  for (int i = 1; i <= n; ++i) dp[i][i] = 1;

  for (int sz = 2; sz <= n; ++sz) {
    for (int i = 1; i + sz - 1 <= n; ++i) {
      int l = i, r = i + sz - 1;

      dp[l][r] = sz;
      save[l][r] = {0, -1};

      for (int k = l; k < r; ++k) {
        if (dp[l][r] <= dp[l][k] + dp[k + 1][r]) continue;

        dp[l][r] = dp[l][k] + dp[k + 1][r];
        save[l][r] = {1, k};
      }

      string s1 = s.substr(l, sz), s2 = "";
      for (int j = l; j <= r; ++j) {
        s2 += s[j];
        if (!is_valid(s1, s2)) continue;

        int c = s2.size();
        int mul = sz / c;
        if (mul > 9) continue;

        int need = (mul == 1) ? 0 : 3;
        if (dp[l][r] <= dp[l][j] + need) continue;

        dp[l][r] = dp[l][j] + need;
        save[l][r] = {2, j};
      }
    }
  }

  // cout << dp[1][n] << '\n';
  cout << trace(trace, 1, n) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}