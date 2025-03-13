/*
    Code by: KoKoDuDu
*/
class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0, minn = 10001;

        for (int i : prices) {
            minn = Math.min(minn, i);
            ans = Math.max(ans, i - minn);
        }

        return ans;
    }
}