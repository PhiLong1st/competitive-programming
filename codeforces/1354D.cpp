/*
    Code by: KoKoDuDu
    Created: 2025.11.05 16:16:11
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

struct BIT {
  vector<int> bit;
  int n;
  BIT() {}
  BIT(int n) {
    this->n = n;
    bit.assign(n + 37, 0);
  }

  void update(int u, int v) {
    int idx = u;
    while (idx <= n) {
      bit[idx] += v;
      idx += (idx & (-idx));
    }
  }

  int get(int p) {
    int idx = p, ans = 0;
    while (idx > 0) {
      ans += bit[idx];
      idx -= (idx & (-idx));
    }
    return ans;
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  BIT bit(n);

  int x;
  for (int i = 0; i < n; ++i) cin >> x, bit.update(x, 1);

  while (q--) {
    int x;
    cin >> x;

    if (x > 0) {
      bit.update(x, 1);
    } else {
      x = -x;
      int l = 1, r = n, pos = 0;
      while (l <= r) {
        int mid = (l + r) >> 1;
        int cnt = bit.get(mid);

        if (cnt >= x) {
          pos = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }

      if (pos == 0) continue;
      bit.update(pos, -1);
    }
  }

  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int cnt = bit.get(mid);

    if (cnt > 0) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}