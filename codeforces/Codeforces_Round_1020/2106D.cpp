
/*
    Code by: KoKoDuDu
    Created: 2025.04.24 22:04:31
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n + 1), b(m + 1);
  vector<int> l(m + 1), r(m + 2);

  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];

  int pos = 1;
  for (int i = 1; i <= n; ++i) {
    if (a[i] >= b[pos]) {
      l[pos] = i;
      pos++;
    }

    if (pos > m) return void(cout << 0 << '\n');
  }

  pos = m;
  for (int i = n; i >= 1; --i) {
    if (a[i] >= b[pos]) {
      r[pos] = i;
      pos--;
    }

    if (pos < 1) return void(cout << 0 << '\n');
  }

  int ans = INT_MAX;
  for (int i = 1; i <= m; ++i) {
    if (i == 1) {
      if (r[i + 1] != 0) {
        ans = min(ans, b[i]);
      }
    } else if (i == m) {
      if (l[i - 1] != 0) {
        ans = min(ans, b[i]);
      }
    } else if (l[i - 1] < r[i + 1] && l[i - 1] != 0 && r[i + 1] != 0) {
      ans = min(ans, b[i]);
    }
  }
  cout << ((ans == INT_MAX) ? -1 : ans) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}