/*
    Code by: KoKoDuDu
    Created: 2025.11.04 18:11:52
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
  int n, a, b, q;
  cin >> a >> b >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;

    int maxx = max(a, b);
    int lcm = (a * b) / __gcd(a, b);

    int add = 0;
    for (int i = 0; i < maxx; ++i) {
      int x1 = max(0LL, (l - 1 - i) / lcm + (l - 1 - i >= 0));
      int x2 = max(0LL, (r - i) / lcm + (r - i >= 0));
      add += x2 - x1;
    }

    cout << (r - l + 1) - add << ' ';
  }
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

// 100 % 7 = 2, 2 % 11 = 2
// 100 % 11 = 1, 1 % 7 = 1

// 141 % 7 = 1, 1 % 10 = 1
// 141 % 10 = 1, 1 % 7 = 1

// 1 2 3 4 5 6 7 8 9