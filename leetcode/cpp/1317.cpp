/*
    Code by: KoKoDuDu
    Created: 2025.09.08 12:53:14
*/

#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

class Solution {
 public:
  vector<int> getNoZeroIntegers(int n) {
    auto check = [](int x) {
      while (x > 0) {
        if (x % 10 == 0) return false;
        x /= 10;
      }
      return true;
    };
    vector<int> ans(2);
    for (int i = 1; i < n; ++i) {
      int j = n - i;
      if (check(i) && check(j)) {
        ans[0] = i, ans[1] = j;
      }
    }
    return ans;
  }
};