/*
    Code by: KoKoDuDu
    Created: 2025.11.13 21:29:03
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
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& x : a) cin >> x;

  for (int i = 1; i < n; ++i)
    if (abs(a[i] - a[i - 1]) <= 1) return void(cout << 0 << '\n');

  bool is_inc = 1, is_dec = 1;
  for (int i = 1; i < n; ++i) {
    is_inc &= a[i] > a[i - 1];
    is_dec &= a[i] < a[i - 1];
  }

  if (is_inc || is_dec) return void(cout << -1 << '\n');
  cout << "1\n";
}

// 2 4 6 8
// 8 6 4 2

// a < b < c
// a > b > c

// 5 7 3
// a < b > c
// -> c > a
// -> c < a

// 3 > 1 < 5
// 5 > 1 < 3
// a > b < c

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}