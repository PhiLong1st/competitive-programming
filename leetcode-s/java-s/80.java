/*
    Code by: KoKoDuDu
*/
class Solution {
   public int removeDuplicates(int[] nums) {
       if (nums.length <= 2) {
           return nums.length;
       }

       int sz = 2;
       for (int i = 2; i < nums.length; ++i) {
           if (nums[i] == nums[i - 1] && nums[i] == nums[sz - 2]) {
               continue;
           }
           nums[sz++] = nums[i];
       }
       return sz;
   }
}