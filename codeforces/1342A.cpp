/*
    Code by: KoKoDuDu
    Created: 2025.11.04 18:05:33
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
#define el '\n'

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
  int x, y, a, b;
  cin >> x >> y >> a >> b;

  if (a * 2 <= b) return void(cout << (x + y) * a << el);

  int minn = min(x, y);
  int maxx = max(x, y);
  cout << minn * b + (maxx - minn) * a << el;
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