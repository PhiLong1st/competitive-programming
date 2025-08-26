/*
    Code by: KoKoDuDu
    Created: 2025.08.26 10:58:18
*/

#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;

  if (k <= n / 2) {
    for (int i = 0; i < n - k; ++i) {
      cout << 2;
    }
    for (int i = n - k; i < n; ++i) {
      cout << 3;
    }
  } else {
    for (int i = 0; i < k; ++i) {
      cout << 1;
    }
    for (int i = k; i < n; ++i) {
      cout << 4;
    }
  }
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