class Solution {
 public:
  int maxSumDivThree(vector<int>& nums) {
    int ans = 0;
    vector<vector<int>> rem(3, vector<int>());
    for (auto& x : nums) {
      rem[x % 3].push_back(x);
      ans += x;
    }

    for (int i = 0; i < 3; ++i) sort(rem[i].begin(), rem[i].end());

    if (ans % 3 == 0) return ans;

    int minn = INT_MAX;
    if (ans % 3 == 2) {
      if (rem[1].size() >= 2) minn = min(minn, rem[1][0] + rem[1][1]);
      if (rem[2].size() >= 1) minn = min(minn, rem[2][0]);
    }

    if (ans % 3 == 1) {
      if (rem[1].size() >= 1) minn = min(minn, rem[1][0]);
      if (rem[2].size() >= 2) minn = min(minn, rem[2][0] + rem[2][1]);
    }

    return ans - minn;
  }
};