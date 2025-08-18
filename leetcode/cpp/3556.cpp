/*
    Code by: KoKoDuDu

*/
class Solution {
public:
    // int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    //     int ans = -1;
    //     int l = 0, r = queries.size() - 1;

    //     if (*max_element(nums.begin(), nums.end()) == 0) {
    //         return 0;
    //     }

    //     while (l <= r) {
    //         int mid = (l + r) / 2;
    //         bool isOk = true;
    //         vector<int> tmp(nums.size() + 1);

    //         for (int i = 0; i <= mid; ++i) {
    //             tmp[queries[i][0]] += queries[i][2];
    //             tmp[queries[i][1] + 1] -= queries[i][2];
    //         }

    //         for (int i = 0; i < nums.size(); ++i) {
    //             if (i != 0) {
    //                 tmp[i] += tmp[i - 1];
    //             }

    //             isOk &= tmp[i] >= nums[i];
    //         }

    //         if (isOk) {
    //             r = mid - 1;
    //             ans = mid + 1;
    //         } else {
    //             l = mid + 1;
    //         }
    //     }
    //     return ans;
    // }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            while (sum + cnt[i] < nums[i]) {
                if (k == queries.size())
                    return -1;
                int l = queries[k][0];
                int r = queries[k][1];
                int val = queries[k][2];
                k++;

                if (r < i)
                    continue;
                cnt[max(l, i)] += val;
                cnt[r + 1] -= val;
            }
            sum += cnt[i];
        }
        return k;
    }
};