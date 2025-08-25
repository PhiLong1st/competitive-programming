/*
    Code by: KoKoDuDu
    Created: 2025.08.25 16:33:06
*/

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    vector<int> diagonal_order_elements(rows * cols);

    int index = 0;
    int diagonal_number = cols + rows - 1;

    auto is_in_bounds = [&](int r, int c) {
      return 0 <= r && r < rows && 0 <= c && c < cols;
    };

    for (int i = 0; i < diagonal_number; ++i) {
      bool is_main_diagonal = i % 2 == 0;
      int cur_row, cur_col;

      if (is_main_diagonal) {
        cur_row = min(i, rows - 1);
        cur_col = (i < rows) ? 0 : i - rows + 1;

        while (is_in_bounds(cur_row, cur_col)) {
          diagonal_order_elements[index++] = mat[cur_row--][cur_col++];
        }
      } else {
        cur_col = min(i, cols - 1);
        cur_row = (i < cols) ? 0 : i - cols + 1;

        while (is_in_bounds(cur_row, cur_col)) {
          diagonal_order_elements[index++] = mat[cur_row++][cur_col--];
        }
      }
    }

    return diagonal_order_elements;
  }
};