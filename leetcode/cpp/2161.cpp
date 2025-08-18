/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int cnt = 0;
        for (int x : nums) {
            if (x < pivot) {
                ans[cnt++] = x;
            }
        }
        for (int x : nums) {
            if (x == pivot) {
                ans[cnt++] = x;
            }
        }
        for (int x : nums) {
            if (x > pivot) {
                ans[cnt++] = x;
            }
        }
        return ans;
    }
};