/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/sum-of-variable-length-subarrays/description/
*/
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans = 0;
        vector<int> sum(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            sum[i] += (i == 0) ? 0 : sum[i - 1];
            sum[i] += nums[i];
            cout << sum[i] << ' ';
        }
        for (int i = 0; i < nums.size(); ++i) {
            int pos = max(0, i - nums[i]);
            ans += sum[i] - ((pos == 0) ? 0 : sum[pos - 1]);
        }
        return ans;
    }
};