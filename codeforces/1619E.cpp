/*
    Code by: KoKoDuDu
    Created: 2025.09.06 13:08:27
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n;
  cin >> n;
  vector<int> prequency(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    int num;
    cin >> num;
    prequency[num]++;
  }

  stack<array<int, 2>> available_numbers;
  int current_cost = 0;
  bool can_construct_mex = true;

  for (int mex = 0; mex <= n; ++mex) {
    if (!can_construct_mex) {
      cout << -1 << ' ';
      continue;
    }

    cout << current_cost + prequency[mex] << ' ';

    available_numbers.push({mex, prequency[mex] - 1});

    if (prequency[mex] == 0) {
      while (!available_numbers.empty() && available_numbers.top()[1] <= 0) {
        available_numbers.pop();
      }

      if (available_numbers.empty()) {
        can_construct_mex = false;
      } else {
        current_cost += mex - available_numbers.top()[0];
        available_numbers.top()[1]--;
      }
    }
  }

  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}