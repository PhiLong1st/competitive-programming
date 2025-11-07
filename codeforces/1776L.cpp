/*
    Code by: KoKoDuDu
    Created: 2025.11.06 22:16:23
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

  string s;
  cin >> s;

  int u = 0, v = 0;
  for (auto& c : s) u += c == '+', v += c == '-';

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;

    if (u == v) {
      cout << "YES" << '\n';
      continue;
    }

    if (a == b) {
      cout << "NO" << '\n';
      continue;
    }

    int dx = b * u - b * v;
    int dt = a - b;

    if (dx % dt != 0) {
      cout << "NO" << '\n';
      continue;
    }

    int d = dx / dt;
    int lx = -d, rx = v - d;

    lx = max(lx, 0LL);
    rx = min(rx, u);

    if (lx > rx) {
      cout << "NO" << '\n';
      continue;
    }

    cout << "YES" << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}