/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
*/
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, sum = 0;
        int cntOdd = 0, cntEven = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            if (sum % 2 == 0) {
                ans += cntOdd;
                ans %= MOD;
                cntEven++;
            } else {
                ans += cntEven + 1;
                ans %= MOD;
                cntOdd++;
            }
        }
        return ans;
    }
};