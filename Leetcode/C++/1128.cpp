/*
    Code by: KoKoDuDu
    Created: 2025.05.04 09:07:30
*/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        map<pair<int, int>, int> cnt;
        for (auto d : dominoes) {
            cnt[make_pair(min(d[0], d[1]), max(d[0], d[1]))]++;
        }
        for (auto c : cnt) {
            ans += c.second * (c.second - 1) / 2;
        }
        return ans;
    }
};