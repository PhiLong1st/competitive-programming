#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static bool ComparePairs(const vector<int>& a, const vector<int>& b) {
    return (a[0] == b[0]) ? a[1] < b[1] : a[0] > b[0];
  }

  int numberOfPairs(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), ComparePairs);
    int n = points.size();
    int count = 0;

    for (int i = 0; i < n - 1; ++i) {
      int minY = INT_MAX;
      for (int j = i + 1; j < n; ++j) {
        if (points[j][1] >= points[i][1] && points[j][1] < minY) {
          ++count;
          minY = points[j][1];
        }
      }
    }

    return count;
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
