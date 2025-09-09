/*
    Code by: KoKoDuDu
    Created: 2025.09.09 15:41:19
*/

#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;
const long long kInf = 1e18;

class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long long> dp(n + 1);
    dp[1] = 1;
    long long cnt = 0;
    for (int i = 2; i <= n; ++i) {
      if (i > delay) {
        cnt = (cnt + dp[i - delay]) % kMod;
      }
      if (i > forget) {
        cnt = (cnt - dp[i - forget] + kMod) % kMod;
      }
      dp[i] = cnt;
    }

    long long ans = 0;
    for (int i = n - forget + 1; i <= n; ++i) {
      ans = (ans + dp[i]) % kMod;
    }
    return (int)ans;
  }
};