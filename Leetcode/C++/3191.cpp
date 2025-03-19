/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0) {
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
                ans++;
            }
        }

        if (nums[n - 1] != 1 || nums[n - 2] != 1) {
            return -1;
        }

        return ans;
    }
};