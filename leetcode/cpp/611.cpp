/*
    Code by: KoKoDuDu
    Created: 2025.09.26 08:38:03
*/

#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;

class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int triangle_number = 0;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        int minus = nums[i] - nums[j];
        int pos = upper_bound(nums.begin(), nums.end(), minus) - nums.begin();
        triangle_number += max(j - pos, 0);
      }
    }

    return triangle_number;
  }
};