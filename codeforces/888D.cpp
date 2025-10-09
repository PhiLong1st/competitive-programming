/*
    Code by: KoKoDuDu
    Created: 2025.10.09 11:44:35
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> fact(k + 1);

  fact[0] = 1;
  for (int i = 1; i <= k; ++i) fact[i] = fact[i - 1] * i;

  int ans = 0;
  for (int x = 0; x <= k; ++x) {
    int cnt = fact[x];
    for (int i = 1; i <= x; ++i) {
      int mul = (i % 2) ? -1 : 1;
      cnt += mul * fact[x] / fact[i];
    }

    for (int i = 0; i < x; ++i) cnt *= n - i;

    ans += cnt / fact[x];
  }

  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}