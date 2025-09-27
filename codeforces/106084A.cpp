/*
    Code by: KoKoDuDu
    Created: 2025.09.27 13:39:22
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int a, b;
  cin >> a >> b;

  cout << ((2 * a <= b) ? "double it" : "take it");
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