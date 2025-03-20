/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/?envType=daily-question&envId=2025-03-20
*/
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
        vector<vector<int>>& query) {
        int q = query.size();
        int m = edges.size();
        int cnt = 0;

        vector<int> ans(q), inSame(n), val(n + 1);
        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
        map<pair<int, int>, int> cap;

        for (auto x : edges) {
            int u = x[0], v = x[1], w = x[2];

            if (u > v) {
                swap(u, v);
            }

            if (cap.count({ u, v }) > 0)
                cap[{u, v}] &= w;
            else
                cap[{u, v}] = w;
        }

        for (auto x : cap) {
            int u = x.first.first, v = x.first.second, w = x.second;

            adj[u].push_back({ v, cap[{u, v}] });
            adj[v].push_back({ u, cap[{u, v}] });
            // cout << x.first.first << ' ' << x.first.second << ' ' << x.second << '\n';
        }

        function<void(int, int&)> dfs = [&](int x, int& andTotal) {
            inSame[x] = cnt;
            // cout << x << ' ' << andTotal << '\n';
            for (auto [v, w] : adj[x]) {
                andTotal = (andTotal == -1) ? w : (andTotal & w);
                if (inSame[v] == 0) {
                    dfs(v, andTotal);
                }
            }
            };

        for (int i = 0; i < n; ++i) {
            if (inSame[i] == 0) {
                ++cnt;
                int andTotal = -1;
                dfs(i, andTotal);
                val[cnt] = andTotal;
                // cout << cnt << ' ' << andTotal<< '\n';
            }
        }

        for (int i = 0; i < q; ++i) {
            int u = query[i][0], v = query[i][1];

            if (inSame[u] == inSame[v]) {
                ans[i] = val[inSame[u]];
            }
            else {
                ans[i] = -1;
            }
        }

        return ans;
    }
};