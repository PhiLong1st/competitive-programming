/*
    Code by: KoKoDuDu
    Created: 2025.08.26 10:55:38
*/

class Solution {
 public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int maximum_area = 0;
    int maximum_square_diagonal = 0;

    for (auto dimension : dimensions) {
      int w = dimension[0], h = dimension[1];
      int square_diagonal = w * w + h * h;
      if (maximum_square_diagonal < square_diagonal) {
        maximum_square_diagonal = square_diagonal;
        maximum_area = w * h;
      } else if (maximum_square_diagonal == square_diagonal) {
        maximum_area = max(maximum_area, w * h);
      }
    }

    return maximum_area;
  }
};