/*
    Code by: KoKoDuDu
    Created: 2025.10.19 08:24:09
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
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

static inline void add_mod(int& a, int b) {
  a = a + b;
  if (a >= kMod) a -= kMod;
}

static inline int mul_mod(int a, int b) {
  a = a * b % kMod;
  return a;
}

struct Point {
  int x, y;

  Point() {}
  Point(int x, int y) : x(x), y(y) {}

  inline bool operator<(const Point& p) const {
    return ((x < p.x) || (x == p.x && y < p.y));
  }
};

int cross(const Point& O, const Point& A, const Point& B) {
  return ((A.x - O.x) * (B.y - O.y)) - ((A.y - O.y) * (B.x - O.x));
}

vector<Point> get_convex_hull(vector<Point> P) {
  int i, t, k = 0, n = P.size();
  vector<Point> H(n << 1);
  sort(P.begin(), P.end());

  for (i = 0; i < n; i++) {
    while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
    H[k++] = P[i];
  }
  for (i = n - 2, t = k + 1; i >= 0; i--) {
    while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
    H[k++] = P[i];
  }

  H.resize(k - 1);
  return H;
}

int sqr(int x) { return x * x; }

void solve() {
  int n;
  cin >> n;

  vector<Point> polygon(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    polygon[i] = Point(x, y);
  }

  vector<Point> hull = get_convex_hull(polygon);

  // cout << (int)hull.size() << '\n';
  // for (auto [x, y] : hull) {
  //   cout << x << ' ' << y << '\n';
  // }

  int ans = 0;
  for (int i = 0; i < hull.size(); ++i) {
    for (int j = i + 1; j < hull.size(); ++j) {
      ans = max(ans, sqr(hull[i].x - hull[j].x) + sqr(hull[i].y - hull[j].y));
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