
/*
    Code by: KoKoDuDu
    Created: 2025.03.22 12:59:12
*/
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec,
        vector<vector<string>>& ing,
        vector<string>& sup) {
        unordered_map<string, vector<string>> graph;
        int n = rec.size();
        unordered_set<string> s;
        for (auto x : sup)
            s.insert(x);

        unordered_map<string, int> indegree;
        for (auto x : rec)
            indegree[x] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int)ing[i].size(); j++) {
                if (s.find(ing[i][j]) == s.end()) {
                    graph[ing[i][j]].push_back(rec[i]);
                    indegree[rec[i]]++;
                }
            }
        }

        queue<string> q;
        for (auto x : indegree) {
            if (x.second == 0) {
                q.push(x.first);
            }
        }
        vector<string> ans;
        while (!q.empty()) {
            string tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for (auto nbr : graph[tmp]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return ans;
    }
};