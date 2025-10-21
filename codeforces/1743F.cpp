/*
    Code by: KoKoDuDu
    Created: 2025.10.21 15:45:41
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

const int kMod = 998244353;
const int kMaxN = 3e5 + 5;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

int add_mod(int a, int b) { return a + b >= kMod ? a + b - kMod : a + b; }

int mul_mod(int a, int b) { return a * b % kMod; }

struct Matrix {
  int mtx[2][2];
  Matrix() { mtx[0][0] = mtx[0][1] = mtx[1][0] = mtx[1][1] = 0; }
};

Matrix operator*(const Matrix& mtx_a, const Matrix& mtx_b) {
  Matrix mtx_res;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx_res.mtx[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        int mul = mul_mod(mtx_a.mtx[i][k], mtx_b.mtx[k][j]);
        mtx_res.mtx[i][j] = add_mod(mtx_res.mtx[i][j], mul);
      }
    }
  }
  return mtx_res;
}

struct Segment_Tree {
  vector<Matrix> st;
  int n;

  Segment_Tree(int n) {
    this->n = n;
    st.assign(4 * n + 37, Matrix());
  }

  void update(int id, int l, int r, int pos, const Matrix& val) {
    if (l == r) {
      st[id] = val;
      return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid) {
      update(id * 2, l, mid, pos, val);
    } else {
      update(id * 2 + 1, mid + 1, r, pos, val);
    }

    st[id] = st[id * 2] * st[id * 2 + 1];
  }

  Matrix get_mul(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return Matrix();

    if (u <= l && r <= v) return st[id];

    int mid = (l + r) >> 1;
    Matrix mtx1 = get_mul(id * 2, l, mid, u, v);
    Matrix mtx2 = get_mul(id * 2 + 1, mid + 1, r, u, v);
    return mtx1 * mtx2;
  }
};

void solve() {
  int n, maxx = 0;
  cin >> n;

  vector<pii> segs(n + 1);
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    maxx = max(maxx, r);
    segs[i] = {l, r};
  }

  vector<vector<int>> add(maxx + 1 + 1), del(maxx + 1 + 1);
  for (int i = 1; i <= n; i++) {
    add[segs[i].fi].push_back(i);
    del[segs[i].se].push_back(i);
  }

  Matrix mtx0;
  mtx0.mtx[0][0] = 3;
  mtx0.mtx[0][1] = 0;
  mtx0.mtx[1][0] = 1;
  mtx0.mtx[1][1] = 2;

  Matrix mtx1;
  mtx1.mtx[0][0] = 1;
  mtx1.mtx[0][1] = 2;
  mtx1.mtx[1][0] = 1;
  mtx1.mtx[1][1] = 2;

  int m = n - 1;
  Segment_Tree seg_tree(m);

  for (int pos = 1; pos <= m; ++pos) seg_tree.update(1, 1, m, pos, mtx0);

  int a0 = 0;
  int ans = 0;
  for (int i = 0; i <= maxx + 1; ++i) {
    for (int j : add[i]) {
      if (j == 1) {
        a0 = 1;
      } else {
        seg_tree.update(1, 1, m, j - 1, mtx1);
      }
    }

    Matrix prod = seg_tree.get_mul(1, 1, m, 1, m);
    ans = add_mod(ans, prod.mtx[a0][1]);

    for (int j : del[i]) {
      if (j == 1) {
        a0 = 0;
      } else {
        seg_tree.update(1, 1, m, j - 1, mtx0);
      }
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
