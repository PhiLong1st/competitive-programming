/*
    Code by: KoKoDuDu
    Created: 2025.08.18 16:47:24
*/

class Solution {
 public:
  int maximum69Number(int num) {
    string num_str = to_string(num);

    for (int i = 0; i < num_str.size(); ++i) {
      if (num_str[i] == '6') {
        num_str[i] = '9';
        break;
      }
    }

    int maximum_num = 0;
    for (auto num : num_str) {
      maximum_num = maximum_num * 10 + (num - '0');
    }

    return maximum_num;
  }
};