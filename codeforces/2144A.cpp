/*
    Code by: KoKoDuDu
    Created: 2025.10.09 18:10:45
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
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &c : a) cin >> c;

  for (int i = 0; i < n; ++i) {
    a[i] += (i == 0 ? 0 : a[i - 1]);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int l = a[i] % 3;
      int r = (a[n - 1] - a[j]) % 3;
      int mid = (a[j] - a[i]) % 3;

      if ((l == r && l == mid) || (l != r && l != mid && r != mid)) {
        cout << i + 1 << ' ' << j + 1 << '\n';
        return;
      }
    }
  }

  cout << 0 << ' ' << 0 << '\n';
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