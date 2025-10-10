/*
    Code by: KoKoDuDu
    Created: 2025.10.10 01:41:56
*/

#include <bits/stdc++.h>
#define int long long
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
  return (a >= 0) ? (a + b - 1) / b : a / b;
}

static inline int fdiv(int a, int b) {
  return (a <= 0) ? (a - b + 1) / b : a / b;
}

struct Diophantine {
  int ext_gcd(int a, int b, int &x, int &y) {
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

  bool solve_any(int a, int b, int c, int &x0, int &y0, int &g) {
    g = ext_gcd(abs(a), abs(b), x0, y0);

    if (c % g != 0) return false;

    x0 *= c / g;
    y0 *= c / g;

    x0 = a < 0 ? -x0 : x0;
    y0 = b < 0 ? -y0 : y0;

    return true;
  }

  bool find_range(int a, int b, int c, int minx, int maxx, int miny, int maxy,
                  int &kL, int &kR) {
    if (a == 0 || b == 0) return false;

    // a, b != 0
    // x = x0 + t * stepX, y = y0 - t * stepY
    // minx <= x <= maxx -> kLx <= t <= kRx
    // miny <= y <= maxy -> kLy <= t <= kRy
    int x0, y0, g, kLx, kRx, kLy, kRy;

    if (!solve_any(a, b, c, x0, y0, g)) return false;

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

void solve() {
  int n, m, a, b, c;
  cin >> n >> m >> a >> b >> c;

  Diophantine dio;
  int x0, y0, g, kL, kR;
  bool is_ok = dio.solve_any(a, b, c, x0, y0, g);
  is_ok = dio.find_range(a, b, c, 0, n, 0, m, kL, kR);

  if (!is_ok) return void(cout << m + n << '\n');

  int stepX = b / g;
  int stepY = a / g;

  auto f = [&](int k) -> int {
    int x = x0 + k * stepX;
    int y = y0 - k * stepY;

    int x_time = (x == 0) ? kMaxInf : n / x;
    int y_time = (y == 0) ? kMaxInf : m / y;

    return n + m - (x + y) * min(x_time, y_time);
  };

  int ans = kMaxInf;
  int t = kL;
  
  while (t <= kR) {
    int x = x0 + t * stepX;
    int y = y0 - t * stepY;

    int x_cap = (x == 0 ? kMaxInf : n / (n / x));

    int dt1 = max(1LL, cdiv((x_cap + 1) - x, stepX));

    int y_floor_next = (y == 0) ? m : m / (m / y + 1);
    int dt2 = max(1LL, cdiv(y - y_floor_next, stepY));

    int next_t = min(kR + 1, t + min(dt1, dt2));
    int pick = (stepX >= stepY) ? (next_t - 1) : t;

    ans = min(ans, f(pick));

    t = next_t;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}