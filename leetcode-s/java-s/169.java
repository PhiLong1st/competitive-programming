/*
    Code by: KoKoDuDu
*/
class Solution {
    public int majorityElement(int[] nums) {
        int ans = nums[0], cnt = 0;
        for (int i : nums) {
            if (cnt == 0) {
                ans = i;
                cnt++;
            } else {
                cnt += (ans == i) ? 1 : -1;
            }
        }
        return ans;
    }
}