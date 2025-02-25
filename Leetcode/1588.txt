/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
*/
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<int> prefix_sum(n);
        prefix_sum[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + arr[i];
        }
        int sum_odd = 0, sum_even = 0;
        int cnt_odd = 0, cnt_even = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 != 0) {
                ans += prefix_sum[i] * cnt_even - sum_even;
                sum_odd += prefix_sum[i];
                cnt_odd++;
            } else {
                ans += prefix_sum[i] * (cnt_odd + 1) - sum_odd;
                cnt_even++;
                sum_even += prefix_sum[i];
            }
        }
        return ans;
    }
};