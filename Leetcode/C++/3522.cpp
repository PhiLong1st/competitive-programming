/*
    Code by: KoKoDuDu
    Created: 2025.04.20 11:07:42
*/
class Solution {
public:
    long long calculateScore(vector<string>& a, vector<int>& b) {
        long long ans = 0;
        int n = a.size();
        vector<int> vst(n + 1);
        for (int i = 0; i < a.size(); ++i) {
            string s = a[i];
            if (vst[i]) {
                break;
            }
            if (s == "add") {
                ans += b[i];
                vst[i] = 1;
            }
            else {
                vst[i] = 1;
                i += b[i] - 1;
            }

        }

        return ans;
    }
};