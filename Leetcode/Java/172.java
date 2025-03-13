/*
    Code by: KoKoDuDu
*/
class Solution {
    public int trailingZeroes(int n) {
        int cntTwo = 0, cntFive = 0;
        int two = 2, five = 5;

        while (two <= n) {
            cntTwo += n / two;
            two *= 2;
        }

        while (five <= n) {
            cntFive += n / five;
            five *= 5;
        }

        return Math.min(cntTwo, cntFive);
    }
}