/*
    Code by: KoKoDuDu
    Created: 2025.10.05 14:42:04
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int a[4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];

  sort(a, a + 4);

  cout << (a[0] * a[2]) << '\n';
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