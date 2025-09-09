/*
    Code by: KoKoDuDu
    Created: 2025.09.08 22:57:34
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int k, x;
  cin >> k >> x;

  int a = (1LL << (k + 1)) - x;
  if (a == x) {
    cout << 0 << '\n';
    cout << '\n';
    return;
  }

  int pos = 0;
  for (int i = 0; i <= k; ++i) {
    if (x & (1LL << i)) {
      pos = i;
      break;
    }
  }

  cout << k - pos << '\n';
  for (int i = pos + 1; i <= k; ++i) {
    cout << ((x & (1LL << i)) ? 2 : 1) << ' ';
  }
  cout << '\n';
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