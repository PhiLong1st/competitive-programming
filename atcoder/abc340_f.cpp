/*
    Code by: KoKoDuDu
    Created: 2025.10.07 02:15:39
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

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

  int count_solution_in_range(int a, int b, int c, int minx, int maxx, int miny,
                              int maxy) {
    // x = x0 + t * stepX, y = y0 + t * stepY
    int x0, y0, g;
    if (!solve_any(a, b, c, x0, y0, g)) return 0;

    int stepX = b / g;
    int stepY = a / g;

    // minx <= x <= maxx -> kLx <= t <= kRx
    int kLx, kRx;
    if (stepX > 0) {
      kLx = (int)ceil((double)(minx - x0) / (double)stepX);
      kRx = (int)floor((double)(maxx - x0) / (double)stepX);
    } else if (stepX < 0) {
      kLx = (int)ceil((double)(maxx - x0) / (double)stepX);
      kRx = (int)floor((double)(minx - x0) / (double)stepX);
    } else {
      if (x0 < minx || x0 > maxx) return 0;

      kLx = kMinInf / 4;
      kRx = kMaxInf / 4;
    }

    // miny <= y <= maxy -> kLy <= t <= kRy
    int kLy, kRy;
    if (stepY > 0) {
      kLy = (int)ceil((double)(y0 - maxy) / (double)stepY);
      kRy = (int)floor((double)(y0 - miny) / (double)stepY);
    } else if (stepY < 0) {
      kLy = (int)ceil((double)(y0 - miny) / (double)stepY);
      kRy = (int)floor((double)(y0 - maxy) / (double)stepY);
    } else {
      if (y0 < miny || y0 > maxy) return 0;

      kLy = kMinInf / 4;
      kRy = kMaxInf / 4;
    }

    int kL = max(kLx, kLy);
    int kR = min(kRx, kRy);

    return kL > kR ? 0 : kR - kL + 1;
  }
};

void solve() {
  int a, b;
  cin >> a >> b;

  int g = gcd(a, b);

  if (2LL % g != 0) return void(cout << -1);

  Diophantine dio;
  int x, y;
  bool ok = dio.solve_any(b, -a, 2, x, y, g);

  if (!ok) return void(cout << -1);

  cout << x << ' ' << y;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}