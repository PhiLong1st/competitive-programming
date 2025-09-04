/*
    Code by: KoKoDuDu
    Created: 2025.09.04 19:03:08
*/

#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

class Solution {
 public:
  int findClosest(int x, int y, int z) {
    int distance_x_to_z = abs(z - x);
    int distance_y_to_z = abs(z - y);

    if (distance_x_to_z == distance_y_to_z) {
      return 0;
    } else if (distance_x_to_z < distance_y_to_z) {
      return 1;
    } else {
      return 2;
    }
  }
};