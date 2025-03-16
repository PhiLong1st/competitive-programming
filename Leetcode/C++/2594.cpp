/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/minimum-time-to-repair-cars/description/
*/
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans = 0;
        long long l = 0, r = 1e18;
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long tmp = 0;
            for (int t : ranks) {
                tmp += 1LL * sqrt(mid / t);
            }
            if (tmp >= cars) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};