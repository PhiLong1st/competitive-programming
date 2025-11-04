#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
#define el '\n'
#define problem "problem"

using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

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