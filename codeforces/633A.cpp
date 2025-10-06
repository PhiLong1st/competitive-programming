/*
    Code by: KoKoDuDu
    Created: 2025.10.06 16:31:19
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

int gcd(int a, int b, int& x, int& y) {
  x = 1, y = 0;
  int x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  int x, y;
  int g = gcd(a, b, x, y);

  if (c % g != 0) {
    cout << "No\n";
    return;
  }

  x *= c / g;
  y *= c / g;

  a /= g;
  b /= g;

  int left = ceil(1.0 * (-x) / b);
  int right = floor(1.0 * y / a);

  cout << ((left <= right) ? "Yes" : "No");
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