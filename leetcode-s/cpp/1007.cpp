
/*
    Code by: KoKoDuDu
    Created: 2025.05.03 20:37:19
*/
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;

        for (int i = 1; i <= 6; ++i) {
            int cnt = 0, top = 0, bot = 0;
            for (int j = 0; j < tops.size(); ++j) {
                if (tops[j] != i && bottoms[j] != i) {
                    cnt = -1;
                    break;
                }

                if (tops[j] == i) {
                    bot += bottoms[j] != i;
                }

                if (bottoms[j] == i) {
                    top += tops[j] != i;
                }
            }

            if (cnt != -1) {
                ans = min(ans, min(bot, top));
                // cout << i << ' ' << bot << ' ' << top << '\n';
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};