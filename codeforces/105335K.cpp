/*
    Code by: KoKoDuDu
    Created: 2025.10.05 12:31:18
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int num_row, num_col;
  cin >> num_row >> num_col;

  vector<vector<int>> a(num_row + 1, vector<int>(num_col + 1));
  for (int i = 1; i <= num_row; i++) {
    for (int j = 1; j <= num_col; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> mx_right(num_row + 1, vector<int>(num_col + 1, 0));
  for (int i = 1; i <= num_row; i++) {
    for (int j = num_col; j >= 1; j--) {
      mx_right[i][j] =
          (j == num_col) ? a[i][j] : max(mx_right[i][j + 1], a[i][j]);
    }
  }

  vector<int> sum_mx_right(num_row + 1, 0);
  for (int i = num_row; i >= 1; i--) {
    sum_mx_right[i] = (i == num_row) ? mx_right[num_row][1]
                                     : sum_mx_right[i + 1] + mx_right[i][1];
  }
  int res = 0;
  vector<int> dp(num_row * 9 + 1, INT_MIN);
  dp[a[1][1]] = a[1][num_col];

  for (int i = 2; i <= num_row; i++) {
    vector<int> best(10, -1);
    for (int j = 1; j <= num_col - 1; j++) {
      best[a[i][j]] = max(best[a[i][j]], mx_right[i][j + 1]);
    }

    for (int left = dp.size() - 1; left >= 0; left--) {
      int right = dp[left];
      if (right == INT_MIN) continue;

      for (int v = 0; v < 10; v++) {
        if (best[v] == -1) {
          continue;
        }

        dp[left + v] = max(dp[left + v], right + best[v]);
      }

      int sum_below = (i == num_row ? 0 : sum_mx_right[i + 1]);
      res = max(res, left * (right + mx_right[i][1] + sum_below));
      res = max(res, (left + mx_right[i][1] + sum_below) * right);
    }
  }

  for (int i = 0; i < dp.size(); i++) {
    if (dp[i] == INT_MIN) continue;

    res = max(res, i * dp[i]);
  }

  cout << res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}