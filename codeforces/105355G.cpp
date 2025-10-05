/*
    Code by: KoKoDuDu
    Created: 2025.10.04 22:08:52
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int x1, x2, x3, y1, y2, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  cout << x1 - x2 + x3 << ' ' << y1 - y2 + y3 << '\n';
  cout << x1 + x2 - x3 << ' ' << y1 + y2 - y3 << '\n';
  cout << -x1 + x2 + x3 << ' ' << -y1 + y2 + y3 << '\n';
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