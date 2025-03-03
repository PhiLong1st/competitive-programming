/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/transform-array-by-parity/
*/
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            ans.push_back(x % 2);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};