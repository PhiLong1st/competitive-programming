/*
    Code by: KoKoDuDu
    Created: 2025.08.19 09:51:32
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total_subarrays = 0;
        int consecutive_zeros = 0;

        for (auto num : nums) {
            if (num != 0) {
                consecutive_zeros = 0;
                continue;
            }

            total_subarrays += consecutive_zeros + 1;
            consecutive_zeros++;
        }

        return total_subarrays;
    }
};