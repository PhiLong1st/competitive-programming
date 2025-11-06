/*
    Code by: KoKoDuDu
    Created: 2025.11.06 09:30:39
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
  int n, q;
  cin >> n >> q;

  if (n == 1) {
    while (q--) {
      string s;
      int k;
      cin >> s >> k;
      cout << 1 << '\n';
    }
    return;
  }

  vector<int> row(n), col(n);
  for (int i = 0; i < n; ++i) row[i] = col[i] = i % 2;

  int cnt_row = n, cnt_col = n, ans = n * n;

  auto upd = [&](vector<int>& t, int& cnt, int k, int d) -> void {
    if (k + 1 < n) {
      cnt += (t[k] == t[k + 1]);
      cnt -= (t[k] != t[k + 1]);

      ans += (t[k] == t[k + 1]) * d;
      ans -= (t[k] != t[k + 1]) * d;
    }

    if (k - 1 >= 0) {
      cnt += (t[k] == t[k - 1]);
      cnt -= (t[k] != t[k - 1]);

      ans += (t[k] == t[k - 1]) * d;
      ans -= (t[k] != t[k - 1]) * d;
    }

    t[k] = 1 - t[k];
  };

  while (q--) {
    string s;
    int k;
    cin >> s >> k;
    --k;

    if (s == "ROW") {
      upd(row, cnt_row, k, cnt_col);
    } else {
      upd(col, cnt_col, k, cnt_row);
    }

    cout << ans << '\n';
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