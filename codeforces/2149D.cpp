/*
    Code by: KoKoDuDu
    Created: 2025.09.25 22:08:11
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  string s;
  int n;
  cin >> n >> s;

  if (n <= 2) {
    return void(cout << 0 << '\n');
  }

  int ans = kInf;
  for (auto c : {'a', 'b'}) {
    vector<int> cnt(n + 1), sum(n + 1);
    for (int i = 1; i <= n; ++i) {
      cnt[i] = cnt[i - 1] + (s[i - 1] == c);
      sum[i] = sum[i - 1] + ((s[i - 1] == c) ? i : 0);
    }

    for (int i = 1; i < n; ++i) {
      int sum_left = sum[i];
      int num_left = cnt[i];

      int sum_right = sum[n] - sum[i];
      int num_right = cnt[n] - cnt[i];

      int res_left = (num_left * i) - sum_left - (num_left - 1) * (num_left / 2);
      int res_right =
          sum_right - (i + 1) * num_right - (num_right - 1) * num_right / 2;

      ans = min(ans, res_left + res_right);
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

  while (t--) {
    solve();
  }

  return 0;
}