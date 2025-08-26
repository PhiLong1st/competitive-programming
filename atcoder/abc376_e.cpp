/*
    Code by: KoKoDuDu
    Created: 2025.08.26 18:19:33
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int subset_size, nums_size;
  cin >> nums_size >> subset_size;

  vector<array<int, 2>> nums(nums_size);
  for (auto &c : nums) {
    cin >> c[0];
  }
  for (auto &c : nums) {
    cin >> c[1];
  }

  sort(nums.begin(), nums.end());
  priority_queue<int> pq;

  int minimum_value = kInf;
  int current_sum = 0;
  for (int i = 0; i < subset_size - 1; ++i) {
    pq.push(nums[i][1]);
    current_sum += nums[i][1];
  }

  for (int i = subset_size - 1; i < nums_size; ++i) {
    int cur_value = nums[i][0] * (current_sum + nums[i][1]);
    minimum_value = min(minimum_value, cur_value);

    if (pq.empty()) continue;

    int max_val = pq.top();
    if (max_val > nums[i][1]) {
      current_sum -= max_val;
      current_sum += nums[i][1];
      pq.pop();
      pq.push(nums[i][1]);
    }
  }
  cout << minimum_value << '\n';
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