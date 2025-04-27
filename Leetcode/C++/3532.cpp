
/*
    Code by: KoKoDuDu
    Created: 2025.04.27 13:16:36
*/
class Solution {
public:
    struct DSU {
        vector<int> par, level;
        DSU(int n) : par(n), level(n, 1) { iota(par.begin(), par.end(), 0); }

        int find(int x) {
            if (par[x] != x) {
                par[x] = find(par[x]);
            }
            return par[x];
        }

        void join(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (level[rootX] > level[rootY]) {
                    par[rootY] = rootX;
                }
                else if (level[rootX] < level[rootY]) {
                    par[rootX] = rootY;
                }
                else {
                    par[rootY] = rootX;
                    level[rootX]++;
                }
            }
        }
    };

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
        vector<vector<int>>& q) {
        vector<bool> ans;
        vector<int> pos(nums.size());
        iota(pos.begin(), pos.end(), 0);
        sort(pos.begin(), pos.end(),
            [&](int a, int b) { return nums[a] < nums[b]; });

        DSU dsu(n);

        for (int i = 1; i < n; ++i) {
            if (nums[pos[i]] - nums[pos[i - 1]] > maxDiff) {
                continue;
            }
            dsu.join(pos[i], pos[i - 1]);
        }

        for (auto t : q) {
            int u = t[0], v = t[1];
            ans.push_back(dsu.find(u) == dsu.find(v));
        }
        return ans;
    }
};