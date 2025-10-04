/*
    Code by: KoKoDuDu
    Created: 2025.10.03 23:26:19
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n < 3) {
      for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << -1 << '\n';
      }
      continue;
    }

    vector<int> cnt1(n + 1, 0);
    for (int i = 0; i < n; i++) cnt1[i + 1] = cnt1[i] + (a[i] == 1);

    vector<int> dist(n);
    dist[0] = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[i - 1])
        dist[i] = 1;
      else
        dist[i] = dist[i - 1] + 1;
    }

    int logn = 0;
    while ((1 << logn) <= n) logn++;
    vector<vector<int>> sp(n, vector<int>(logn, 0));
    for (int i = 0; i < n; i++) sp[i][0] = dist[i];
    for (int k = 1; k < logn; k++) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        sp[i][k] = max(sp[i][k - 1], sp[i + (1 << (k - 1))][k - 1]);
      }
    }

    auto get_max = [&](int l, int r) -> int {
      if (l > r) return 0;
      int len = r - l + 1;
      int k = 31 - __builtin_clz(len);
      return max(sp[l][k], sp[r - (1 << k) + 1][k]);
    };

    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;

      if ((r - l + 1) % 3 != 0 || (cnt1[r + 1] - cnt1[l]) % 3 != 0 ||
          l + 2 > r) {
        cout << -1 << '\n';
        continue;
      }

      int max_dist = get_max(l + 1, r);
      int total = r - l + 1;

      if (max_dist == 1)
        cout << 2 + (total - 3) / 3 << '\n';
      else
        cout << total / 3 << '\n';
    }
  }
  return 0;
}