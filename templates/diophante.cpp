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