/*
    Code by: KoKoDuDu
    Created: 2025.10.24 22:30:20
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

  vector<int> a(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;

  vector<int> ord;
  for (int i = 1; i <= n; i++) ord.push_back(pos[i]);

  for (int i : ord) {
    int p = a[i] - 2;
    while (p >= 1 && p + 1 <= n && min(pos[p], pos[p + 1]) > i) {
      a[i] = p;
      a[pos[p]] = p + 1;
      a[pos[p + 1]] = p + 2;

      pos[p + 2] = pos[p + 1];
      pos[p + 1] = pos[p];
      pos[p] = i;
      p = a[i] - 2;
    }
  }

  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
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