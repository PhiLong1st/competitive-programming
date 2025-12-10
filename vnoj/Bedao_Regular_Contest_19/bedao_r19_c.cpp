#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int ans = 0;
  unordered_map<int, int> dp;
  int last = -1;
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    int t = dp[x + 1];
    dp[x] = max(dp[x], t + 1);
    if (ans < dp[x]) {
      ans = dp[x];
      last = i;
    }
  }

  int val = a[last];

  stack<int> path;
  for (int i = last; i >= 1; --i) {
    if (a[i] != val) continue;
    path.push(i);
    val++;
  }

  cout << ans << '\n';
  while (!path.empty()) {
    cout << path.top() << ' ';
    path.pop();
  }
}
