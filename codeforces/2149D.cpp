/*
    Code by: KoKoDuDu
    Created: 2025.09.25 22:08:11
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

int calc(int l, int r, int mid, vector<int>& cnt, vector<int>& sum) {
  int sum_left = sum[mid] - sum[l - 1];
  int num_left = cnt[mid] - cnt[l - 1];

  int sum_right = sum[r] - sum[mid];
  int num_right = cnt[r] - cnt[mid];

  int res_left = num_left * mid - sum_left - (num_left - 1) * num_left / 2;
  int res_right =
      sum_right - (mid + 1) * num_right - (num_right - 1) * num_right / 2;

  return res_left + res_right;
}

void solve() {
  string s;
  int n;
  cin >> n >> s;

  if (n <= 2) {
    return void(cout << 0 << '\n');
  }

  vector<int> cnt_a(n + 1), sum_a(n + 1);
  vector<int> cnt_b(n + 1), sum_b(n + 1);

  for (int i = 1; i <= n; ++i) {
    cnt_a[i] = cnt_a[i - 1] + (s[i - 1] == 'a');
    sum_a[i] = sum_a[i - 1] + ((s[i - 1] == 'a') ? i : 0);

    cnt_b[i] = cnt_b[i - 1] + (s[i - 1] == 'b');
    sum_b[i] = sum_b[i - 1] + ((s[i - 1] == 'b') ? i : 0);
  }

  int ans = kInf;
  for (int i = 1; i < n; ++i) {
    ans = min(ans, calc(1, n, i, cnt_a, sum_a));
    ans = min(ans, calc(1, n, i, cnt_b, sum_b));
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