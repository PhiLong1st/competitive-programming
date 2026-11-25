/*
 Code by: Algorillas
 Created: 2026.09.05 18:00:04
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
const int N = 2511;

vector<int> f[N];
void sieve() {
  for (int i = 1; i * i < N; i++) {
    for (int j = i; j * i < N; ++j) {
      f[i * j].push_back(i);
      if (i != j) f[i * j].push_back(j);
    }
  }
}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char x;
      cin >> x;
      a[i][j] = (x == '#');
    }
  }

  int _g = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 1) {
        cnt++;
      } else {
        if (cnt) _g = gcd(_g, cnt);
        cnt = 0;
      }
    }
    if (cnt) _g = gcd(_g, cnt);
  }

  for (int j = 0; j < m; ++j) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i][j] == 1) {
        cnt++;
      } else {
        if (cnt) _g = gcd(_g, cnt);
        cnt = 0;
      }
    }
    if (cnt) _g = gcd(_g, cnt);
  }

  vector<int> valid;
  unordered_map<int, int> f_cnt;
  for (auto c : f[_g]) {
    if (c > 1) {
      valid.push_back(c);
    }
  }

  vector<vector<int>> pref(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      pref[i][j] = a[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] -
                   pref[i - 1][j - 1];
    }
  }

  auto get = [&](int x, int y, int u, int v) -> int {
    return pref[u][v] - pref[x - 1][v] - pref[u][y - 1] + pref[x - 1][y - 1];
  };
  dbg(valid);

  auto get_and_fill = [](vector<vector<int>>& ca, int i, int j, int v) -> int {
    int res = 0;
    for (int x = i; x < i + v; ++x) {
      for (int y = j; y < j + v; ++y) {
        res += ca[x][y];
        ca[x][y] = 0;
      }
    }
    return res;
  };

  int res = 1;
  for (auto v : valid) {
    dbg(v);
    bool ok = true;
    auto c_a = a;

    // for (int i = 0; i < n; ++i)
    //   for (int j = 0; j < m; ++j) cerr << c_a[i][j] << " \n"[j == m - 1];
    // cerr << '\n';

    for (int i = 0; i < n - v + 1; ++i) {
      for (int j = 0; j < m - v + 1; ++j) {
        if (!c_a[i][j]) continue;
        int total = get_and_fill(c_a, i, j, v);

        // cerr << "after: \n";
        // for (int i = 0; i < n; ++i)
        //   for (int j = 0; j < m; ++j) cerr << c_a[i][j] << " \n"[j == m - 1];
        // cerr << "----\n\n";

        if (total != v * v && total > 0) {
          ok = false;
          break;
        }
      }

      if (!ok) break;
    }

    // for (int i = 0; i < n; ++i)
    //   for (int j = 0; j < m; ++j) cerr << c_a[i][j] << " \n"[j == m - 1];
    // cerr << '\n';

    if (ok) res = max(res, v);
  }

  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  sieve();
  solve();
  return 0;
}