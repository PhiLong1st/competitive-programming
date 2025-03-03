/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/
*/
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = INT_MAX;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        queue<pair<pair<int, int>, int>> save;
        save.push({{0, 0}, 0});
        dp[0][0] = 0;
        while (!save.empty()) {
            auto [curr, cost] = save.front();
            save.pop();
            int x = curr.first, y = curr.second;
            if (dp[x][y] < cost)
                continue;
            if (x == m - 1 && y == n - 1) {
                ans = min(ans, dp[x][y]);
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                int new_cost = cost + (grid[x][y] != i + 1);
                if (dp[nx][ny] > new_cost) {
                    dp[nx][ny] = new_cost;
                    save.push({{nx, ny}, new_cost});
                }
            }
        }
        return ans;
    }
};