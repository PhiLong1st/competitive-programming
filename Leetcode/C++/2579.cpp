/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/count-total-number-of-colored-cells/
*/
class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1) {
            return 1LL;
        }
        return 1LL * (n - 1) * n * 2 + 1;
    }
};