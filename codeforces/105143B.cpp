/*
    Code by: KoKoDuDu
    Created: 2025.10.09 22:53:38
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

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  int total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    total += a[i];
  }

  int ans = 0;
  for (int bit = 30; bit >= 0; --bit) {
    if (n * ((1LL << bit) - 1) >= total) continue;

    total -= min(n, total / (1LL << bit)) * (1LL << bit);
    ans |= (1LL << bit);
  }

  cout << ans;
  return 0;
}