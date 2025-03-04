/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/
*/
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 > 1) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};