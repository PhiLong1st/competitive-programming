/*
    Code by: KoKoDuDu
    Created: 2025.11.07 15:42:10
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
const int kMaxM = 37;
const int kMod = 998244353;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void add_mod(int& a, int b) { a = (a + b >= kMod) ? a + b - kMod : a + b; }

struct Matrix {
  int r, c;
  vector<vector<int>> mtx;
  Matrix(int r, int c) : r(r), c(c), mtx(r, vector<int>(c)) {}
};

Matrix operator*(const Matrix& mtx_a, const Matrix& mtx_b) {
  Matrix mtx_res(mtx_a.r, mtx_b.c);
  for (int i = 0; i < mtx_a.r; i++) {
    for (int j = 0; j < mtx_b.c; j++) {
      int val = 0;
      for (int k = 0; k < mtx_a.c; k++) {
        val += (mtx_a.mtx[i][k] * mtx_b.mtx[k][j]) % kMod;
        if (val >= kMod) val -= kMod;
      }
      mtx_res.mtx[i][j] = val;
    }
  }
  return mtx_res;
}

Matrix fpow(const Matrix& x, int y) {
  Matrix res(x.r, x.c);
  for (int i = 0; i < min(x.r, x.c); i++) res.mtx[i][i] = 1;
  Matrix cur = x;
  while (y) {
    if (y & 1) res = res * cur;
    cur = cur * cur;
    y >>= 1;
  }
  return res;
}

int n, r, m, sp_pts, k;
pii st_pts;
pii pts[kMaxM];
bool can_reach[kMaxM][kMaxM];

static int sqr(int x) { return x * x; }

static int dist(pii a, pii b) { return sqr(a.fi - b.fi) + sqr(a.se - b.se); }

void solve() {
  cin >> n >> r >> st_pts.fi >> st_pts.se >> m;

  for (int i = 1; i <= m; ++i) cin >> pts[i].fi >> pts[i].se;

  cin >> sp_pts >> k;

  auto can_jump = [&](pii a, pii b) -> bool { return dist(a, b) <= sqr(r); };

  bool can_start = false;
  for (int i = 1; i <= m; ++i) {
    if (can_jump(st_pts, pts[i])) {
      can_start = true;
      break;
    }
  }

  if (!can_start) return void(cout << (k == 0) << " 1\n");

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      can_reach[i][j] = can_jump(pts[i], pts[j]);
    }
  }

  Matrix g(1, m);
  for (int i = 0; i < m; ++i) g.mtx[0][i] = can_jump(st_pts, pts[i + 1]);

  Matrix trans_g(m, m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      trans_g.mtx[i][j] = can_reach[i + 1][j + 1];
    }
  }

  g = g * fpow(trans_g, n - 1);
  int total_ways = 0;
  for (int i = 0; i < m; ++i) add_mod(total_ways, g.mtx[0][i]);

  if (k == 0) return void(cout << total_ways << ' ' << total_ways << '\n');

  if (k > n) return void(cout << 0 << ' ' << total_ways << '\n');

  auto get_id = [&](int i, int used) -> int { return (i - 1) * k + used; };

  Matrix f(1, m * k);
  for (int i = 1; i <= m; ++i) {
    if (!can_jump(st_pts, pts[i])) continue;

    if (i == sp_pts) {
      f.mtx[0][get_id(i, 1)] = 1;
    } else {
      f.mtx[0][get_id(i, 0)] = 1;
    }
  }

  Matrix trans_f(m * k, m * k);
  for (int i = 1; i <= m; ++i) {
    for (int used = 0; used <= k - 1; ++used) {
      int from = get_id(i, used);
      for (int j = 1; j <= m; ++j) {
        if (!can_reach[i][j]) continue;

        if (j == sp_pts) {
          if (used + 1 <= k - 1) {
            int to = get_id(j, used + 1);
            trans_f.mtx[from][to] = 1;
          }
        } else {
          int to = get_id(j, used);
          trans_f.mtx[from][to] = 1;
        }
      }
    }
  }

  f = f * fpow(trans_f, n - 1);
  int ways = 0;
  for (int i = 1; i <= m; ++i) {
    for (int used = 0; used <= k - 1; ++used) {
      add_mod(ways, f.mtx[0][get_id(i, used)]);
    }
  }

  cout << (total_ways - ways + kMod) % kMod << ' ' << total_ways << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
