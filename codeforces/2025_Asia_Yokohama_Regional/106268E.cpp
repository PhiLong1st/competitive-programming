/*
 Code by: Algorillas
 Created: 2026.09.07 21:11:13
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int calc(int x, pair<int, int> f) { return (x * f.second / f.first) + 1; }

void solve() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  // pair<int, int> l = {0, 1};
  // pair<int, int> r = {min({a, b, c}), 1};
  // pair<int, int> best = {-1, -1};
  long double l = 1e-9, r = min({1.0 * a, 1.0 * b, 1.0 * c});
  long double ans = 0;

  for (int i = 0; i < 200; ++i) {
    // int tu = l.first * r.second + r.first * l.second;
    // int mau = 2 * l.second * r.second;
    // int g = gcd(tu, mau);

    // pair<int, int> mid = {tu / g, mau / g};
    auto mid = (l + r) / 2;

    int x = (a / mid);
    int y = (b / mid);
    int z = (c / mid);

    int cnt = max({0ll, x * z * y});

    // cerr << mid.first << ' ' << mid.second << ' ' << cnt << '\n';

    dbg(mid);

    if ((x * y >= k || x * z >= k || z * y >= k) || cnt >= k) {
      l = mid;
      ans = mid;
    } else {
      r = mid;
    }
  }

  assert((int)(ans) <= (int)1e9);
  int tu = ans * 1e9;
  int _g = gcd(tu, (int)1e9);
  cout << tu / _g << ' ' << (int)(1e9) / _g << '\n';
  // cout << best.first << ' ' << best.second << '\n';/
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}