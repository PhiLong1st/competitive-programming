/*
    Code by: KoKoDuDu
    Created: 2025.03.25 17:19:07
*/
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;

        sort(meetings.begin(), meetings.end());
        int x = -1, y = -1;
        for (auto i : meetings) {
            int l = i[0], r = i[1];
            if (l > y) {
                ans += (x == -1) ? 0 : (y - x + 1);
                x = l, y = r;
            }
            else {
                y = max(y, r);
            }
            // cout << i[0] << ' ' << i[1] << ' ';
            // cout << x << ' ' << y << '\n';
        }
        ans += (x == -1) ? 0 : (y - x + 1);

        return days - ans;
    }
};