#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
  int n;
  cin >> n;
  vector<array<int, 3>> a(n);
  vector<int> mn(n), mx(n);
  int low = 1, high = 1000;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
      mn[i] = min(mn[i], a[i][j]);
      mx[i] = max(mx[i], a[i][j]);
    }
  }

  auto is_ok = [&](int limit, int id) -> pair<bool, int> {
    int value = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
      auto& x = a[i];
      int min_id = -1;
      for (int j = id; j < 3; j++) {
        if (x[j] >= limit) {
          if (min_id == -1)
            min_id = j;
          else if (x[min_id] > x[j])
            min_id = j;
        }
      }
      if (min_id == -1) return {false, -1};
      swap(x[min_id], x[id]);
      value = min(value, x[2]);
    }
    return {true, value};
  };
  int res = LONG_LONG_MIN;
  for (int w = low; w <= high; w++) {
    if (!is_ok(w, 0).first) break;
    for (int h = low; h <= high; h++) {
      auto [ok, d] = is_ok(h, 1);
      if (!ok) break;
      res = max(res, w * h * d);
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