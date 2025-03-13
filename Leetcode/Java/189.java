/*
    Code by: KoKoDuDu
*/
class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        int[] tmp = new int[2 * n];

        for (int i = 0; i < 2 * n; ++i) {
            tmp[i] = nums[i % n];
        }

        for (int i = n - k; i < 2 * n - k; ++i) {
            nums[i - n + k] = tmp[i];
        }
    }
}