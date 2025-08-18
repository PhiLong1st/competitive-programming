/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/divide-array-into-equal-pairs/description/
*/
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> cnt;

        for (int x : nums) {
            cnt[x]++;
        }

        for (auto x : cnt) {
            if (x.second % 2) {
                return false;
            }
        }

        return true;
    }
};