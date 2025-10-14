/*
    Code by: KoKoDuDu
    Created: 2025.10.13 22:24:18
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

static inline int cdiv(int a, int b) {
  return a >= 0 ? (a + b - 1) / b : a / b;
}

static inline int fdiv(int a, int b) {
  return a <= 0 ? (a - b + 1) / b : a / b;
}

void solve() {
  int n, f;
  cin >> n >> f;

  int temp_f = f;

  vector<tuple<int, int, int>> a(n);
  vector<int> used(n), path;

  int r_max = 0;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    a[i] = make_tuple(l, r, i);
    r_max = max(r_max, r);
  }

  auto cmp = [&](tuple<int, int, int> x, tuple<int, int, int> y) -> bool {
    auto [lx, rx, _] = x;
    auto [ly, ry, _] = y;

    if (lx == ly) return rx < ry;
    return lx < ly;
  };

  sort(a.begin(), a.end(), cmp);

  int ans = 0;
  int pos = 0;
  while (f < r_max) {
    bool is_found = false;
    while (pos < n) {
      auto [l, r, id] = a[pos];

      if (f > r) {
        pos++;
        continue;
      }

      if (l > f) break;

      ans += r - l;
      f = r;

      pos++;
      is_found = true;
      used[id] = true;
      path.push_back(id);
      break;
    }

    if (is_found) continue;
    auto [l, r, id] = a[pos];

    ans += r - f;
    f = r;

    pos++;
    used[id] = true;
    path.push_back(id);
  }

  auto cmp2 = [&](tuple<int, int, int> x, tuple<int, int, int> y) -> bool {
    auto [lx, rx, idx] = x;
    auto [ly, ry, idy] = y;

    return rx > ry;
  };

  sort(a.begin(), a.end(), cmp2);

  for (int i = 0; i < n; ++i) {
    auto [l, r, id] = a[i];
    if (used[id]) continue;

    ans += r - l;
    path.push_back(id);
  }

  cout << ans << '\n';
  for (auto &p : path) {
    cout << p + 1 << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--) solve();
  return 0;
}