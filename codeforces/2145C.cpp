/*
    Code by: KoKoDuDu
    Created: 2025.10.06 21:54:07
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  map<int, vector<int>> pre;

  int ans = kInf;
  int state = 0;

  pre[0].push_back(0);
  for (int i = 1; i <= n; ++i) {
    state += (s[i - 1] == 'a') ? 1 : -1;
    pre[state].push_back(i);

    if (state == 0) ans = min(ans, n - i);
  }

  state = 0;
  for (int i = n; i >= 1; --i) {
    state += (s[i - 1] == 'a') ? 1 : -1;

    if (state == 0) ans = min(ans, i - 1);

    auto it_vec = pre.find(-state);
    if (it_vec == pre.end()) {
      continue;
    }

    auto &vec = it_vec->second;
    auto it = lower_bound(vec.begin(), vec.end(), i);
    if (it == vec.begin()) continue;

    --it;
    ans = min(ans, i - *it - 1);
  }

  cout << (ans != kInf ? ans : -1) << '\n';
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