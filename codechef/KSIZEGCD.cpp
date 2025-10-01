/*
    Code by: KoKoDuDu
    Created: 2025.10.01 11:16:13
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SparseTable {
  vector<vector<int>> spt;
  vector<int> arr;
  int n{}, LG{};

  explicit SparseTable(const vector<int>& a) { init(a); }

  void init(const vector<int>& a) {
    arr = a;
    n = (int)arr.size();
    LG = 1;
    while ((1 << LG) <= n) ++LG;
    spt.assign(LG, vector<int>(n));
    build();
  }

  void build() {
    for (int i = 0; i < n; ++i) spt[0][i] = arr[i];
    for (int k = 1; k < LG; ++k) {
      for (int i = 0; i + (1 << k) <= n; ++i) {
        spt[k][i] = __gcd(spt[k - 1][i], spt[k - 1][i + (1 << (k - 1))]);
      }
    }
  }

  int get_gcd(int l, int r) const {
    if (l > r) return 0;
    int len = r - l + 1;
    int k = 31 - __builtin_clz(len);
    return __gcd(spt[k][l], spt[k][r - (1 << k) + 1]);
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  SparseTable spt(a);
  vector<int> ans(n);

  auto extend = [&](int i, int l, int val) -> int {
    int lo = l, hi = n - 1, best = l - 1;

    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (spt.get_gcd(i, mid) == val) {
        best = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    return best;
  };

  for (int i = 0; i < n; ++i) {
    int r = i;
    while (r < n) {
      int g = spt.get_gcd(i, r);
      int pos = extend(i, r, g);
      int len = pos - i + 1;
      ans[len - 1] = max(ans[len - 1], g);
      r = pos + 1;
    }
  }

  for (int i = n - 2; i >= 0; --i) {
    ans[i] = max(ans[i], ans[i + 1]);
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i + 1 == n ? '\n' : ' ');
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
