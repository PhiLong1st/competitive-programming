
/*
    Code by: KoKoDuDu
    Created: 2025.04.24 22:42:58
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> l(n + 1), r(n + 1);
  s = " " + s + " ";

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '0') {
      l[i] = n - i;
      if (s[i - 1] == '0') l[i] += l[i - 1];
    }
  }

  for (int i = n; i >= 1; --i) {
    if (s[i] == '0') {
      r[i] = i - 1;
      if (s[i + 1] == '0') r[i] += r[i + 1];
    }
  }

  for (int i = 1; i <= n; ++i) {
    int res = 0;
    if (s[i] == '1') {
      res = 1;
      if (s[i - 1] == '0') res += l[i - 1];
      if (s[i + 1] == '0') 
        res += r[i + 1];
    }
    ans = max({ans, l[i], r[i]});
    ans = max(ans, res);
  }
  cout << ans << "\n";
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