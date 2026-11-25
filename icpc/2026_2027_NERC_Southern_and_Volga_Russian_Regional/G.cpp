#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int m;
  cin >> m;
  sort(a.begin() + 1, a.end(), greater<>());
  if (a[1] >= m) {
    cout << -1;
    return;
  }
  m -= a[1];
  int res = 0;
  int l = 0;
  int r = a[2];
  auto is_good = [&](int level) {
    int take = 0;
    for (int i = 2; i <= n; i++) {
      if (a[i] <= level) break;
      take += a[i] - level;
    }
    return take >= m;
  };
  while (l <= r) {
    int mid = (l + r) / 2;
    if (is_good(mid)) {
      res = max(res, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  if (fopen("in.txt", "r")) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}