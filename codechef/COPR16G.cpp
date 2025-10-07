/*
    Code by: KoKoDuDu
    Created: 2025.10.07 17:24:20
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
  int a, b;
  cin >> a >> b;

  int g = gcd(a, b);
  if (g != 1) {
    cout << -1 << '\n';
  } else {
    int n = (a * b - a - b + 1);
    cout << n << '\n';
  }
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