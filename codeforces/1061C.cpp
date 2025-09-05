/*
    Code by: KoKoDuDu
    Created: 2025.09.05 11:56:29
*/

#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;
const int kMaxDiv = 1e6;

void solve() {
  int n;
  cin >> n;

  vector<int> numbers(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> numbers[i];
  }

  vector<int> dp(kMaxDiv + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int current_number = numbers[i];
    priority_queue<int> divs;

    for (int div = 1; div * div <= current_number; ++div) {
      if (current_number % div == 0) {
        divs.push(div);
        if (div * div != current_number) {
          divs.push(current_number / div);
        }
      }
    }

    while (!divs.empty()) {
      int div = divs.top();
      dp[div] = (dp[div] + dp[div - 1]) % kMod;
      divs.pop();
    }
  }

  int total_sequences = 0;
  for (int i = 1; i < dp.size(); ++i) {
    total_sequences = (total_sequences + dp[i]) % kMod;
  }
  cout << total_sequences;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}
