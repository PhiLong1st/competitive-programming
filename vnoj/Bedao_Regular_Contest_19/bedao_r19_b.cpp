#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  auto calc_lis = [&](vector<int>& arr) -> int {
    vector<int> b = arr;

    int sz = arr.size();
    vector<int> f(sz, 1e12);

    sort(b.begin(), b.end());

    int res = 0;
    for (int i = 0; i < sz; ++i) {
      int pos = lower_bound(f.begin(), f.end(), arr[i]) - f.begin();
      f[pos] = a[i];
      res = max(res, pos + 1);
    }
    return res;
  };

  int ans = 0;
  for (int bit = 0; bit < 30; ++bit) {
    vector<int> save;
    for (int i = 1; i <= n; ++i) {
      if (!((1ll << bit) & a[i])) continue;
      save.push_back(a[i]);
    }

    if (save.size() == 0) continue;
    ans = max(ans, (int)save.size());
  }
  cout << ans;
}
