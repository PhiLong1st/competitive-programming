/*
    Code by: KoKoDuDu
    Created: 2025.10.06 12:33:44
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct EG {
  int g, x, y;
};

EG exgcd(int a, int b) {
  if (!b) return {a, 1, 0};
  auto t = exgcd(b, a % b);
  return EG{t.g, t.y, t.x - (a / b) * t.y};
}

int mod_inv(int a, int mod) {
  auto t = exgcd(a, mod);
  int x = t.x % mod;
  if (x < 0) x += mod;
  return x;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, k;
  while (cin >> n >> m >> a >> k) {
    if (n == 0 && m == 0 && a == 0 && k == 0) break;

    if (m == 0 && a == 0) {
      if (n == k)
        cout << n << "\n";
      else
        cout << "Impossible\n";
      continue;
    }

    if (m == 0) {
      if (n >= k + a && ((n - k) % a == 0))
        cout << n << "\n";
      else
        cout << "Impossible\n";
      continue;
    }

    if (a == 0) {
      if (k >= n && (n - k) % m == 0)
        cout << k << "\n";
      else
        cout << "Impossible\n";
      continue;
    }

    int g = gcd(m, a);
    if ((k - n) % g != 0) {
      cout << "Impossible\n";
      continue;
    }

    int m1 = m / g, a1 = a / g;
    m1 = (m1 % a1 + a1) % a1;

    int rhs = (k - n) / g;

    int inv = mod_inv(m1, a1);
    int x = rhs * inv % a1;

    int pos = n + m * x;

    int lcm_a_m = (m * a) / g;
    int start = max(n, k + a);

    if (pos < start) {
      int d = (start - pos + lcm_a_m - 1) / lcm_a_m;
      pos += d * lcm_a_m;
    }

    cout << pos << "\n";
  }
  return 0;
}
