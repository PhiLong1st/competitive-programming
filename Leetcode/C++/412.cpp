/*
    Code by: KoKoDuDu
    Created: 2025.08.18 16:45:54
*/

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> ansArr(n);

    for (int i = 0; i < ansArr.size(); ++i) {
      int oneBaseIdx = i + 1;
      if (oneBaseIdx % 15 == 0) {
        ansArr[i] = "FizzBuzz";
      } else if (oneBaseIdx % 3 == 0) {
        ansArr[i] = "Fizz";
      } else if (oneBaseIdx % 5 == 0) {
        ansArr[i] = "Buzz";
      } else {
        ansArr[i] = to_string(oneBaseIdx);
      }
    }

    return ansArr;
  }
};