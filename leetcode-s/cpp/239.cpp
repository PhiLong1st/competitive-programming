/*
    Code by: KoKoDuDu
    Created: 2025.03.25 17:19:58
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        deque<int> que;

        for (int i = 0; i < nums.size(); ++i) {
            while (!que.empty() && i - que.front() >= k) {
                que.pop_front();
            }

            while (!que.empty() && nums[que.back()] < nums[i]) {
                que.pop_back();
            }

            if (i >= k - 1) {
                if (que.empty()) {
                    ans.push_back(nums[i]);
                }
                else {
                    ans.push_back(nums[que.front()]);
                }
            }

            que.push_back(i);
        }

        return ans;
    }
};