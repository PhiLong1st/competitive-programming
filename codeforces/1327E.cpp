/*
    Code by: KoKoDuDu
    Created: 2025.09.07 17:13:34
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 998244353;

int mod_mul(int a, int b, int n) {
  int ret = 0;
  for (; b; b >>= 1) {
    if (b & 1) {
      ret = ret + a;
      if (ret >= n) ret %= n;
    }
    a = a + a;
    if (a >= n) a %= n;
  }
  return ret;
}

int mod_exp(int b, int p, int n) {
  int ret = 1;
  for (; p; p >>= 1) {
    if (p & 1) ret = mod_mul(ret, b, n);
    b = mod_mul(b, b, n);
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  if (n == 1) return void(cout << 10);

  for (int i = 1; i <= n - 2; ++i) {
    int mul = mod_exp(10, n - i - 1, kMod);
    cout << (180 + 81 * (n - i - 1)) * mul % kMod << ' ';
  }

  cout << 180 << ' ' << 10;
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