/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/house-robber-iv/description/
*/
class Solution {
public:
    bool calc(vector<int>& nums, int k, int mid) {
        int i = 0, n = nums.size();

        while (i < n) {
            if (nums[i] <= mid) {
                k--, i += 2;
            }
            else {
                i++;
            }

            if (k == 0) {
                return true;
            }
        }

        return k == 0;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 1e9 + 1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (calc(nums, k, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};