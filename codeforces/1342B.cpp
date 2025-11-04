/*
    Code by: KoKoDuDu
    Created: 2025.11.04 18:49:36
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
  string t;
  cin >> t;

  int n = t.size();
  if (n == 1) return void(cout << t << '\n');

  bool ok = true;
  for (int i = 1; i < n; ++i) ok &= t[i] == t[i - 1];

  if (ok) return void(cout << t << '\n');

  int f = t[0] == '1';
  for (int i = 0; i < 2 * n; ++i) cout << (i % 2 == 0 ? f : 1 - f);
  cout << '\n';
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