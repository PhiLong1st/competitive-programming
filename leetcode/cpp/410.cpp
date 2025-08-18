/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/split-array-largest-sum/description/
*/
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int ans = 0;
        long long l = *max_element(nums.begin(), nums.end()), r = 1e9;
        while (l <= r) {
            long long mid = (l + r) / 2;
            int cnt = 0;
            for (int i = 0; i < nums.size(); ++i) {
                int val = nums[i];
                while (i < nums.size() - 1 && val + nums[i + 1] <= mid) {
                    val += nums[++i];
                }
                cnt++;
            }
            if (cnt <= k) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};