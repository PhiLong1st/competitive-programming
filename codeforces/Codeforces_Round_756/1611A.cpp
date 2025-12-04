/*
    Code by: KoKoDuDu
    Created: 17.02.2025 13:31:06
    Link: https://codeforces.com/problemset/problem/1611/A
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  if ((s.back() - '0') % 2 == 0) {
    cout << 0 << '\n';
  } else if ((s[0] - '0') % 2 == 0) {
    cout << 1 << '\n';
  } else {
    for (auto x : s) {
      if ((x - '0') % 2 == 0) {
        cout << 2 << '\n';
        return;
      }
    }
    cout << -1 << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}