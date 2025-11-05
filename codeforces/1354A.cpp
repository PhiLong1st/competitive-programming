/*
    Code by: KoKoDuDu
    Created: 2025.11.05 00:11:27
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (b >= a) return void(cout << b << '\n');
  if (c <= d) return void(cout << -1 << '\n');

  int t = c - d;
  cout << b + c * ((a - b + t - 1) / t) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}