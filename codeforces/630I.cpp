/*
    Code by: KoKoDuDu
    Created: 2025.10.02 23:48:58
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n;
  cin >> n;

  if (n == 3) {
    return void(cout << 24);
  }

  int ans = 0;
  ans = 8 * 3 * pow(4, n - 3);
  ans += 36 * pow(4, n - 4) * (n - 3);
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