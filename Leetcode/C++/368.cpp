
/*
    Code by: KoKoDuDu
    Created: 2025.04.07 12:28:46
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans, dp(n + 7, 1), trace(n + 7, -1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = max(dp[i], dp[j] + 1);
                        trace[i] = j;
                    }
                }
            }
        }
        int kq = 0;
        for (int i = 0; i < n; i++) {
            if (dp[kq] < dp[i]) {
                kq = i;
            }
            // cout<<dp[i]<<" ";
        }
        // cout << kq << " " << dp[kq];
        while (kq != -1) {
            // cout << nums[kq] << " ";
            // cout<<trace[kq]<<" ";
            ans.push_back(nums[kq]);
            kq = trace[kq];
        }

        return ans;
    }
};
