/*
    Code by: KoKoDuDu
    Created: 2025.08.22 17:04:16
*/

class Solution {
 public:
  int minimumArea(vector<vector<int>> &grid) {
    pair<int, int> up_left_cell = {INT_MAX, INT_MAX},
                   down_right_cell = {-1, -1};

    int row = grid.size();
    int col = grid[0].size();

    for (int r = 0; r < row; ++r) {
      for (int c = 0; c < col; ++c) {
        if (grid[r][c] == 0) continue;
        up_left_cell.first = min(up_left_cell.first, r);
        up_left_cell.second = min(up_left_cell.second, c);
        down_right_cell.first = max(down_right_cell.first, r);
        down_right_cell.second = max(down_right_cell.second, c);
      }
    }

    int minimum_area = (down_right_cell.first - up_left_cell.first + 1) *
                       (down_right_cell.second - up_left_cell.second + 1);
    return minimum_area;
  }
};