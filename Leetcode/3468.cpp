/*
    Code by: KoKoDuDu
    Link : https://leetcode.com/problems/find-the-number-of-copy-arrays/
*/
class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        long long ans = 0, l = -INT_MAX, r = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                ans += (long long)original[i] - original[i - 1];
            }
            l = max(l, (long long)bounds[i][0] - ans);
            r = min(r, (long long)bounds[i][1] - ans);
        }
        return max(0LL, r - l + 1);
    }
};