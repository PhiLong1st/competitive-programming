/*
    Code by: KoKoDuDu
    Created: 2025.09.27 19:00:46
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n;
  cin >> n;
  int ans = 0;

  for (int i = 1; i <= n; ++i) {
    ans += i * i * i * ((i % 2) ? -1 : 1);
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