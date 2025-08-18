/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/
*/
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int black_count = 0, ans = INT_MAX;

        for (int i = 0; i < blocks.size(); i++) {
            if (i - k >= 0 && blocks[i - k] == 'B')
                black_count--;
            if (blocks[i] == 'B')
                black_count++;
            ans = min(ans, k - black_count);
        }

        return ans;
    }
};