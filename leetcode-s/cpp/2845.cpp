
/*
    Code by: KoKoDuDu
    Created: 2025.04.25 11:31:59
*/

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        int n = nums.size();
        vector<int> pf(n + 1);
        map<int, int> save;

        for (int i = 1; i <= n; ++i) {
            pf[i] = pf[i - 1] + (nums[i - 1] % modulo == k);
        }

        for (int i = 1; i <= n; ++i) {
            int rem = pf[i] % modulo;

            ans += rem == k;
            if (rem >= k) {
                ans += save[rem - k];
            }
            else {
                ans += save[rem + modulo - k];
            }

            save[rem]++;
        }

        return ans;
    }
};