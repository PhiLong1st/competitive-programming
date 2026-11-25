/*
 Code by: Algorillas
 Created: 2026.09.03 20:23:30
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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int _g = 0;
  for (auto& c : a) cin >> c, _g = gcd(_g, c);
  if (_g != 1) {
    cout << "1\n1 " << _g << '\n';
    return;
  }
  cout << "2\n";
  cout << "2 3\n3 2";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}