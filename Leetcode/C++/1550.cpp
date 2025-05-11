
/*
    Code by: KoKoDuDu
    Created: 2025.05.11 22:24:21
*/
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;

        for (int num : arr) {
            if (num % 2 != 0) {
                count++;
                if (count == 3) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }

        return false;
    }
};