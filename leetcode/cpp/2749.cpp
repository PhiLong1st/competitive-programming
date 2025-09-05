/*
    Code by: KoKoDuDu
    Created: 2025.09.05 13:07:04
*/

#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

class Solution {
 public:
  int makeTheIntegerZero(int num1, int num2) {
    for (int i = 0; i <= 60; ++i) {
      long long temp_num1 = num1, temp_num2 = num2;
      temp_num1 -= i * temp_num2;

      if (temp_num1 <= 0) {
        continue;
      }

      int bit_count = __builtin_popcountll(temp_num1);
      if (bit_count <= i && i <= temp_num1) {
        return i;
      }
    }
    return -1;
  }
};