/*
    Code by: KoKoDuDu
    Created: 2025.09.07 12:10:19
*/

#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;
const long long kInf = 1e18;

class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> numbers;

    for (int i = -n / 2; i <= n / 2; ++i) {
      if (n % 2 == 0 && i == 0) continue;
      numbers.push_back(i);
    }

    return numbers;
  }
};