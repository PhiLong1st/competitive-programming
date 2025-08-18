/*
    Code by: KoKoDuDu
    Created: 2025.08.18 16:48:07
*/

class Solution {
 public:
  bool isPowerOfFour(int n) {
    if (n <= 0) return false;

    n = llabs(n);

    while (n % 4 == 0) {
      n /= 4;
    }
    return n == 1;
  }
};