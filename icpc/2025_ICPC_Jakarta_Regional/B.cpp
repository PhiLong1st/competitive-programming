/*
 Code by: Algorillas
 Created: 2026.09.03 20:45:55
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int& c : a) cin >> c;

  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    if (i == 0 || i == n - 1) {
      l[i] = 1;
      continue;
    }

    l[i] = min(l[i - 1] + 1, min({a[i - 1] + 1, a[i], a[i + 1] + 1}));
  }

  for (int i = n - 1; i >= 0; --i) {
    if (i == 0 || i == n - 1) {
      r[i] = 1;
      continue;
    }

    r[i] = min(r[i + 1] + 1, min({a[i - 1] + 1, a[i], a[i + 1] + 1}));
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) continue;
    res = max(res, min(l[i], r[i]));
  }

  cout << res;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}