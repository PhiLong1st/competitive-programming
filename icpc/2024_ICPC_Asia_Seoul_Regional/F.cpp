/*
 Code by: Algorillas
 Created: 2026.09.02 22:21:20
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

struct op {
  int idx, u, v;
};

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> a(2, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) a[0][i] = a[1][i] = n - i + 1;

  queue<op> que;
  for (int t = n; t >= 1; --t) {
    pair<int, int> idA = {0, -1}, idB = {1, -1};
    for (int i = 1; i <= n; ++i) {
      if (a[0][i] == t) {
        if (idA.second == -1) {
          idA = make_pair(0, i);
        } else {
          idB = make_pair(0, i);
        }
      }

      if (a[1][i] == t) {
        if (idA.second == -1) {
          idA = make_pair(1, i);
        } else {
          idB = make_pair(1, i);
        }
      }
    }

    auto calc = [&](pair<int, int> id) {
      for (int i = id.second + 1; i <= t; ++i) {
        int costA = i - a[0][i] == 0 ? INT_MIN : i - a[0][i];
        int costB = i - a[1][i] == 0 ? INT_MIN : i - a[1][i];

        if (costA >= costB) {
          que.push({i - 1, a[id.first][id.second], a[0][i]});
          swap(a[id.first][id.second], a[0][i]);
          id = {0, i};
        } else {
          que.push({i - 1, a[id.first][id.second], a[1][i]});
          swap(a[id.first][id.second], a[1][i]);
          id = {1, i};
        }
      }
    };

    if (idA.second < idB.second) swap(idA, idB);

    calc(idA);
    calc(idB);
  }

  int lim = .7f * n * n;
  assert(que.size() <= lim);

  cout << que.size() << "\n";
  while (!que.empty()) {
    auto& [id, u, v] = que.front();
    que.pop();
    cout << id << ' ' << u << ' ' << v << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}