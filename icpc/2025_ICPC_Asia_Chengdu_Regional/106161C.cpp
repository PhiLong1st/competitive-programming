/*
 Code by: Algorillas
 Created: 2026.09.23 22:41:23
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<array<int, 2>>> a(2);
  a[0].resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[0][i][0];
    a[0][i][1] = i + 1;
  }
  a[1].resize(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[1][i][0];
    a[1][i][1] = i + 1;
  }

  sort(all(a[0]), greater<>());
  sort(all(a[1]), greater<>());

  dbg(a[0]);
  dbg(a[1]);

  vector<array<int, 3>> res;

  for (int init = 0; init < 2; ++init) {
    auto cp_a = a;
    int T = cp_a[init].back()[0];
    vector<array<int, 3>> order;
    order.push_back({T, init, cp_a[init].back()[1]});
    int i = 1, j = 0, state = init ^ 1;
    T += k;
    cp_a[init].pop_back();
    for (int _ = 1; _ < n + m && cp_a[0].size() && cp_a[1].size();
         ++_, state ^= 1) {
      if (cp_a[state ^ 1].size() &&
          max(T, cp_a[state].back()[0]) + 2 * k >
              max(T + k, cp_a[state ^ 1].back()[0]) + k) {
        state ^= 1;
        T += k;

        if (cp_a[state].back()[0] > T) {
          T = cp_a[state].back()[0];
        }
        order.push_back({T, state, cp_a[state].back()[1]});
        T += k;
        cp_a[state].pop_back();
        continue;
      }

      if (cp_a[state].back()[0] > T) {
        T = cp_a[state].back()[0];
      }
      order.push_back({T, state, cp_a[state].back()[1]});
      T += k;
      cp_a[state].pop_back();
    }

    while (cp_a[0].size()) {
      if (state == 1) T += k;
      if (cp_a[0].back()[0] > T) {
        T = cp_a[0].back()[0];
      }
      order.push_back({T, 0, cp_a[0].back()[1]});
      T += 2 * k;
      cp_a[0].pop_back();
    }

    while (cp_a[1].size()) {
      if (state == 0) T += k;
      if (cp_a[1].back()[0] > T) {
        T = cp_a[1].back()[0];
      }
      order.push_back({T, 1, cp_a[1].back()[1]});
      T += 2 * k;
      cp_a[1].pop_back();
    }

    if (res.empty()) {
      res = order;
    } else {
      if (res.back()[0] > order.back()[0]) {
        res = order;
      }
    }
  }
  cout << res.back()[0] + k << '\n';
  for (auto& c : res) {
    cout << c[0] << ' ' << c[1] << ' ' << c[2] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}