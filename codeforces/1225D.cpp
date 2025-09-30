/*
    Code by: KoKoDuDu
    Created: 2025.09.28 11:28:27
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n + 1);
  map<vector<pair<int, int>>, int> mp;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  auto normalize = [&](int x) -> vector<pair<int, int>> {
    vector<pair<int, int>> lst;
    for (int j = 2; j * j <= x; ++j) {
      if (x % j) continue;

      int cnt_pow = 0;
      while (x % j == 0) {
        x /= j;
        ++cnt_pow;
      }

      cnt_pow %= k;
      if (cnt_pow) lst.push_back({j, cnt_pow});
    }

    if (x != 1) {
      lst.push_back({x, 1});
    }

    return lst;
  };

  auto complement =
      [&](const vector<pair<int, int>>& v) -> vector<pair<int, int>> {
    vector<pair<int, int>> u;
    u.reserve(v.size());

    for (auto [p, e] : v) {
      int need = k - e;
      if (need) u.push_back({p, need});
    }

    return u;
  };

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    auto vt = normalize(a[i]);
    auto ops = complement(vt);

    ans += mp[ops];
    mp[vt]++;
  }

  cout << ans;
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