/*
    Code by: KoKoDuDu
    Created: 2025.10.27 13:43:12
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
#define el '\n'
using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<long long>::max();
const int kMinInf = numeric_limits<long long>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

struct Combinatorics {
  int n;
  vector<int> fact, inv, fact_inv;

  Combinatorics(int n) : n(n), fact(n + 1), inv(n + 1), fact_inv(n + 1) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      inv[i] = kMod - (kMod / i) * inv[kMod % i] % kMod;
    }
    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[i] = fact[i - 1] * i % kMod;
      fact_inv[i] = fact_inv[i - 1] * inv[i] % kMod;
    }
  }

  int get_nCk(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * fact_inv[k] % kMod * fact_inv[n - k] % kMod;
  }

  int get_inv_fact(int i) { return fact_inv[i]; }
  int get_fact(int i) { return fact[i]; }
  int get_inv(int i) { return inv[i]; }
};

struct Diophantine {
  int cdiv(int a, int b) { return (a >= 0) ? (a + b - 1) / b : a / b; }
  int fdiv(int a, int b) { return (a <= 0) ? (a - b + 1) / b : a / b; }

  int ext_gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    int x1, y1;
    int g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
  }

  bool try_solve_any(int a, int b, int c, int& x0, int& y0, int& g) {
    g = ext_gcd(llabs(a), llabs(b), x0, y0);
    if (c % g != 0) return false;
    x0 *= c / g;
    y0 *= c / g;
    x0 = a < 0 ? -x0 : x0;
    y0 = b < 0 ? -y0 : y0;
    return true;
  }

  bool try_find_range(int a, int b, int c, int minx, int maxx, int miny,
                      int maxy, int& kL, int& kR) {
    if (a == 0 || b == 0) return false;
    int x0, y0, g, kLx, kRx, kLy, kRy;
    if (!try_solve_any(a, b, c, x0, y0, g)) return false;
    int stepX = b / g;
    int stepY = a / g;
    if (stepX > 0) {
      kLx = cdiv(minx - x0, stepX);
      kRx = fdiv(maxx - x0, stepX);
    } else {
      kLx = cdiv(maxx - x0, stepX);
      kRx = fdiv(minx - x0, stepX);
    }
    if (stepY > 0) {
      kLy = cdiv(y0 - maxy, stepY);
      kRy = fdiv(y0 - miny, stepY);
    } else {
      kLy = cdiv(y0 - miny, stepY);
      kRy = fdiv(y0 - maxy, stepY);
    }
    kL = max(kLx, kLy);
    kR = min(kRx, kRy);
    return kL <= kR;
  }
};

struct Point {
  int x, y;
  Point() : x(0), y(0) {}
  Point(int x, int y) : x(x), y(y) {}
};

struct Line {
  Point ptA, ptB;
  int a, b, c;  // ax + by + c = 0

  Line() : ptA(), ptB(), a(0), b(0), c(0) {}
  Line(Point p, Point q) : ptA(p), ptB(q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -(a * p.x + b * p.y);
  }

  int count_integer_point_on_segment() {
    int dx = ptA.x - ptB.x;
    int dy = ptA.y - ptB.y;
    return gcd(abs(dx), abs(dy)) + 1;
  }

  bool get_integer_intersect_point(Line other, Point& p) {
    int a1 = a, b1 = b, c1 = c;
    int a2 = other.a, b2 = other.b, c2 = other.c;

    int det = a1 * b2 - a2 * b1;
    if (det == 0) return false;

    int x_coor = b1 * c2 - b2 * c1;
    int y_coor = c1 * a2 - c2 * a1;

    if (x_coor % det != 0 || y_coor % det != 0) return false;

    int x = x_coor / det;
    int y = y_coor / det;

    p = Point(x, y);
    return true;
  }

  bool is_contains(Point p) { return a * p.x + b * p.y + c == 0; }

  bool is_on_segment(Point p) {
    int lx = ptA.x, rx = ptB.x;
    int ly = ptA.y, ry = ptB.y;

    if (lx > rx) swap(lx, rx);
    if (ly > ry) swap(ly, ry);

    return lx <= p.x && p.x <= rx && ly <= p.y && p.y <= ry;
  }
};

void solve() {
  int n;
  cin >> n;

  vector<Line> a(n);
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[i] = Line(Point(x1, y1), Point(x2, y2));
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i].count_integer_point_on_segment();

    set<pii> pts;
    for (int j = 0; j < i; ++j) {
      Point p;
      if (!a[i].get_integer_intersect_point(a[j], p)) continue;
      if (!a[i].is_on_segment(p) || !a[j].is_on_segment(p)) continue;
      pts.insert({p.x, p.y});
    }
    ans -= (int)pts.size();
  }

  cout << ans << el;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
