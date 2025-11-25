/*
    Code by: KoKoDuDu
    Created: 2025.11.17 18:51:48
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
const double eps = 1e-9;
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

int add_mod(int a, int b) { return a + b >= kMod ? a + b - kMod : a + b; }

int minus_mod(int a, int b) { return (a - b + kMod) % kMod; }

int mul_mod(int a, int b) { return a * b % kMod; }

void maximize(int& x, int y) { x = max(x, y); }

void minimize(int& x, int y) { x = min(x, y); }

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res;
}

int sign(double x) { return (x > eps) - (x < -eps); }
struct PT {
  double x, y;
  PT() { x = 0, y = 0; }
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT& p) : x(p.x), y(p.y) {}
  PT operator+(const PT& a) const { return PT(x + a.x, y + a.y); }
  PT operator-(const PT& a) const { return PT(x - a.x, y - a.y); }
  PT operator*(const double a) const { return PT(x * a, y * a); }
  friend PT operator*(const double& a, const PT& b) {
    return PT(a * b.x, a * b.y);
  }
  PT operator/(const double a) const { return PT(x / a, y / a); }
  bool operator==(PT a) const {
    return sign(a.x - x) == 0 && sign(a.y - y) == 0;
  }
  bool operator!=(PT a) const { return !(*this == a); }
  bool operator<(PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
  bool operator>(PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
  double norm() { return sqrt(x * x + y * y); }
  double norm2() { return x * x + y * y; }
  PT perp() { return PT(-y, x); }
  double arg() { return atan2(y, x); }
  PT truncate(
      double r) {  // returns a vector with norm r and having same direction
    double k = norm();
    if (!sign(k)) return *this;
    r /= k;
    return PT(x * r, y * r);
  }
};
istream& operator>>(istream& in, PT& p) { return in >> p.x >> p.y; }
ostream& operator<<(ostream& out, PT& p) {
  return out << "(" << p.x << "," << p.y << ")";
}
inline double dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline double dist2(PT a, PT b) { return dot(a - b, a - b); }
inline double dist(PT a, PT b) { return sqrt(dot(a - b, a - b)); }
inline double cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline double cross2(PT a, PT b, PT c) { return cross(b - a, c - a); }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
PT perp(PT a) { return PT(-a.y, a.x); }
PT rotateccw90(PT a) { return PT(-a.y, a.x); }
PT rotatecw90(PT a) { return PT(a.y, -a.x); }
PT rotateccw(PT a, double t) {
  return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t));
}
PT rotatecw(PT a, double t) {
  return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t));
}
double SQ(double x) { return x * x; }
double rad_to_deg(double r) { return (r * 180.0 / PI); }
double deg_to_rad(double d) { return (d * PI / 180.0); }
double get_angle(PT a, PT b) {
  double costheta = dot(a, b) / a.norm() / b.norm();
  return acos(max((double)-1.0, min((double)1.0, costheta)));
}
bool is_point_in_angle(PT b, PT a, PT c,
                       PT p) {  // does point p lie in angle <bac
  assert(orientation(a, b, c) != 0);
  if (orientation(a, c, b) < 0) swap(b, c);
  return orientation(a, c, p) >= 0 && orientation(a, b, p) <= 0;
}
bool half(PT p) { return p.y > 0.0 || (p.y == 0.0 && p.x < 0.0); }
void polar_sort(vector<PT>& v) {  // sort points in counterclockwise
  sort(v.begin(), v.end(), [](PT a, PT b) {
    return make_tuple(half(a), 0.0, a.norm2()) <
           make_tuple(half(b), cross(a, b), b.norm2());
  });
}
void polar_sort(
    vector<PT>& v,
    PT o) {  // sort points in counterclockwise with respect to point o
  sort(v.begin(), v.end(), [&](PT a, PT b) {
    return make_tuple(half(a - o), 0.0, (a - o).norm2()) <
           make_tuple(half(b - o), cross(a - o, b - o), (b - o).norm2());
  });
}
// intersection point between ab and cd assuming unique intersection exists
bool line_line_intersection(PT a, PT b, PT c, PT d, PT& ans) {
  double a1 = a.y - b.y, b1 = b.x - a.x, c1 = cross(a, b);
  double a2 = c.y - d.y, b2 = d.x - c.x, c2 = cross(c, d);
  double det = a1 * b2 - a2 * b1;
  if (det == 0) return 0;
  ans = PT((b1 * c2 - b2 * c1) / det, (c1 * a2 - a1 * c2) / det);
  return 1;
}
struct line {
  PT a, b;  // goes through points a and b
  PT v;
  double c;  // line form: direction vec [cross] (x, y) = c
  line() {}
  // direction vector v and offset c
  line(PT v, double c) : v(v), c(c) {
    auto p = get_points();
    a = p.first;
    b = p.second;
  }
  // equation ax + by + c = 0
  line(double _a, double _b, double _c) : v({_b, -_a}), c(-_c) {
    auto p = get_points();
    a = p.first;
    b = p.second;
  }
  // goes through points p and q
  line(PT p, PT q) : v(q - p), c(cross(v, p)), a(p), b(q) {}
  pair<PT, PT> get_points() {  // extract any two points from this line
    PT p, q;
    double a = -v.y, b = v.x;  // ax + by = c
    if (sign(a) == 0) {
      p = PT(0, c / b);
      q = PT(1, c / b);
    } else if (sign(b) == 0) {
      p = PT(c / a, 0);
      q = PT(c / a, 1);
    } else {
      p = PT(0, c / b);
      q = PT(1, (c - a) / b);
    }
    return {p, q};
  }
  // ax + by + c = 0
  array<double, 3> get_abc() {
    double a = -v.y, b = v.x;
    return {a, b, -c};
  }
  // 1 if on the left, -1 if on the right, 0 if on the line
  int side(PT p) { return sign(cross(v, p) - c); }
  // line that is perpendicular to this and goes through point p
  line perpendicular_through(PT p) { return {p, p + perp(v)}; }
  // translate the line by vector t i.e. shifting it by vector t
  line translate(PT t) { return {v, c + cross(v, t)}; }
  // compare two points by their orthogonal projection on this line
  // a projection point comes before another if it comes first according to
  // vector v
  bool cmp_by_projection(PT p, PT q) { return dot(v, p) < dot(v, q); }
  line shift_left(double d) {
    PT z = v.perp().truncate(d);
    return line(a + z, b + z);
  }
};
PT project_from_point_to_seg(PT a, PT b, PT c) {
  double r = dist2(a, b);
  if (sign(r) == 0) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}
// minimum distance from point c to segment ab
double dist_from_point_to_seg(PT a, PT b, PT c) {
  return dist(c, project_from_point_to_seg(a, b, c));
}
struct circle {
  PT p;
  double r;
  circle() {}
  circle(PT _p, double _r) : p(_p), r(_r) {};
  // center (x, y) and radius r
  circle(double x, double y, double _r) : p(PT(x, y)), r(_r) {};
  // circumcircle of a triangle
  // the three points must be unique
  circle(PT a, PT b, PT c) {
    b = (a + b) * 0.5;
    c = (a + c) * 0.5;
    line_line_intersection(b, b + rotatecw90(a - b), c, c + rotatecw90(a - c),
                           p);
    r = dist(a, p);
  }
  // inscribed circle of a triangle
  // pass a bool just to differentiate from circumcircle
  circle(PT a, PT b, PT c, bool t) {
    line u, v;
    double m = atan2(b.y - a.y, b.x - a.x), n = atan2(c.y - a.y, c.x - a.x);
    u.a = a;
    u.b = u.a + (PT(cos((n + m) / 2.0), sin((n + m) / 2.0)));
    v.a = b;
    m = atan2(a.y - b.y, a.x - b.x), n = atan2(c.y - b.y, c.x - b.x);
    v.b = v.a + (PT(cos((n + m) / 2.0), sin((n + m) / 2.0)));
    line_line_intersection(u.a, u.b, v.a, v.b, p);
    r = dist_from_point_to_seg(a, b, p);
  }
  bool operator==(circle v) { return p == v.p && sign(r - v.r) == 0; }
  double area() { return PI * r * r; }
  double circumference() { return 2.0 * PI * r; }
};

vector<PT> get_convex_hull(vector<PT> P) {
  int i, t, k = 0, n = P.size();
  vector<PT> H(n << 1);
  sort(P.begin(), P.end());
  for (i = 0; i < n; i++) {
    while (k >= 2 && cross2(H[k - 2], H[k - 1], P[i]) < 0) k--;
    H[k++] = P[i];
  }
  for (i = n - 2, t = k + 1; i >= 0; i--) {
    while (k >= t && cross2(H[k - 2], H[k - 1], P[i]) < 0) k--;
    H[k++] = P[i];
  }
  H.resize(k - 1);
  return H;
}

int is_point_in_convex(vector<PT>& p, const PT& x) {  // O(log n)
  int n = p.size();
  assert(n >= 3);
  int a = orientation(p[0], p[1], x), b = orientation(p[0], p[n - 1], x);
  if (a < 0 || b > 0) return 1;
  int l = 1, r = n - 1;
  while (l + 1 < r) {
    int mid = l + r >> 1;
    if (orientation(p[0], p[mid], x) >= 0)
      l = mid;
    else
      r = mid;
  }
  int k = orientation(p[l], p[r], x);
  if (k <= 0) return -k;
  if (l == 1 && a == 0) return 0;
  if (r == n - 1 && b == 0) return 0;
  return -1;
}
void solve() {
  int n, r;
  cin >> n >> r;

  vector<PT> pts;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    pts.emplace_back(x, y);
  }

  PT root = {0, 0};
  circle S(root, r);
  vector<PT> convex = get_convex_hull(pts);

  if (n <= 2 || is_point_in_convex(convex, root) != -1) {
    return void(cout << fixed << setprecision(12) << S.area() / 2);
  }

  double res = 0.0;
  for (int i = 0; i < convex.size(); ++i) {
    PT nx = convex[(i + 1) % (int)convex.size()];
    double d = dist_from_point_to_seg(convex[i], nx, root);
    double line = sqrt(r * r - d * d);
    double angle = acos(d / r) * 2.0 * 180.0 / PI;
    double fS = angle / 360.0 * S.area();
    double aS = fS - d * line;
    res = max(res, min(S.area() - aS, aS));
  }

  cout << fixed << setprecision(12) << res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}