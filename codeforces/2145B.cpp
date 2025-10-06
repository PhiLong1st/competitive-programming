/*
    Code by: KoKoDuDu
    Created: 2025.10.06 21:39:49
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<char> ans(n + 1, '+');

  if (k == n) {
    for (int i = 1; i <= n; ++i) {
      cout << '-';
    }
    cout << '\n';
    return;
  }
  int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
  for (auto c : s) {
    cnt_1 += c == '1';
    cnt_0 += c == '0';
    cnt_2 += c == '2';
  }

  for (int i = 1; i <= cnt_0; ++i) {
    ans[i] = '-';
  }

  for (int i = 1; i <= cnt_1; ++i) {
    ans[n - i + 1] = '-';
  }

  for (int i = 1; i <= cnt_2; ++i) {
    ans[cnt_0 + i] = '?';
    ans[n - cnt_1 + 1 - i] = '?';
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i];
  }

  cout << '\n';
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