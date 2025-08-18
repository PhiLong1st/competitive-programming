/*
    Code by: KoKoDuDu
    Created: 2025.04.20 11:08:07
*/
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int maxx = nums[0];
        for (int i : nums) {
            if (i >= maxx) {
                ans++;
                maxx = i;
            }
        }
        return ans;
    }
};