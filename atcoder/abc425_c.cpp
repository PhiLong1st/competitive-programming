/*
    Code by: KoKoDuDu
    Created: 2025.09.27 19:09:50
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(2 * n + 1);
  vector<int> prefix_sum(2 * n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = n + 1; i <= 2 * n; ++i) {
    a[i] = a[i - n];
  }

  for (int i = 1; i <= 2 * n; ++i) {
    prefix_sum[i] = prefix_sum[i - 1] + a[i];
  }

  int idx = 0;

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int c;
      cin >> c;
      idx += c;
    } else {
      int l, r;
      cin >> l >> r;

      l = (l + idx - 1) % n + 1;
      r = (r + idx - 1) % n + 1;

      if (l <= r)
        cout << prefix_sum[r] - prefix_sum[l - 1] << '\n';
      else {
        cout << prefix_sum[n] - (prefix_sum[l - 1] - prefix_sum[r]) << '\n';
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}