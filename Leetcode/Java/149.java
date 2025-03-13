/*
 * @lc app=leetcode id=149 lang=java
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
    public int maxPoints(int[][] points) {
        // (y1 - y2) * x + (x2 - x1) * y - x1 * y1 - x2 * y2
        int ans = 1;
        for (int i = 0; i < points.length; ++i) {
            int x1 = points[i][0], y1 = points[i][1];

            for (int j = i + 1; j < points.length; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int a = y1 - y2, b = x2 - x1, c = x1 * y2 - x2 * y1;
                int cnt = 0;
                // System.out.println(i + " " + j + " " + a + " " + b + " " + c);

                for (int u = 0; u < points.length; ++u) {
                    int x = points[u][0], y = points[u][1];

                    if (a * x + b * y + c == 0) {
                        cnt++;
                    }
                }

                ans = Math.max(ans, cnt);
            }
        }
        return ans;
    }
}
// @lc code=end

