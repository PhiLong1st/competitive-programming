
/*
    Code by: KoKoDuDu
    Created: 2025.05.07 13:39:32
*/
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({ 0, 0, 0 });
        moveTime[0][0] = 0;

        vector<vector<int>> dir = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int t = current[0];
            int r = current[1];
            int c = current[2];
            if (t >= dp[r][c])
                continue;
            if (r == n - 1 && c == m - 1)
                return t;
            dp[r][c] = t;

            for (auto& direction : dir) {
                int nR = r + direction[0];
                int nC = c + direction[1];
                if (nR >= 0 && nR < n && nC >= 0 && nC < m &&
                    dp[nR][nC] == INT_MAX) {
                    int nextTime = max(moveTime[nR][nC], t) + 1;
                    pq.push({ nextTime, nR, nC });
                }
            }
        }
        return -1;
    }
};