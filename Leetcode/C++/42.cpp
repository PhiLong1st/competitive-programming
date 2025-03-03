/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/trapping-rain-water/description/
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        vector<int> leftMaxx(n + 1), rightMaxx(n + 1);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                leftMaxx[i] = i;
                continue;
            }
            leftMaxx[i] =
                (height[i] < height[leftMaxx[i - 1]]) ? leftMaxx[i - 1] : i;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                rightMaxx[i] = i;
                continue;
            }
            rightMaxx[i] =
                (height[i] < height[rightMaxx[i + 1]]) ? rightMaxx[i + 1] : i;
        }
        for (int i = 0; i < n; i++) {
            if (leftMaxx[i] == i || rightMaxx[i] == i)
                continue;
            ans += min(height[leftMaxx[i]], height[rightMaxx[i]]) - height[i];
        }
        return ans;
    }
};