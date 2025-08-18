
/*
    Code by: KoKoDuDu
    Created: 2025.04.27 13:16:10
*/
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        vector<pair<int, int>> cntX(n + 1), cntY(n + 1);

        for (auto t : buildings) {
            int x = t[0], y = t[1];

            if (cntX[x].first == 0) {
                cntX[x].first = y;
                cntX[x].second = y;
            }

            if (cntY[y].first == 0) {
                cntY[y].first = x;
                cntY[y].second = x;
            }

            cntX[x].first = min(cntX[x].first, y);
            cntX[x].second = max(cntX[x].second, y);
            cntY[y].first = min(cntY[y].first, x);
            cntY[y].second = max(cntY[y].second, x);
        }

        for (auto t : buildings) {
            int x = t[0], y = t[1];
            if (cntY[y].first < x && x < cntY[y].second && cntX[x].first < y &&
                y < cntX[x].second) {
                ans++;
            }
            // cout << cntY[y].first << ' ' << cntY[y].second << '\n';
        }

        return ans;
    }
};