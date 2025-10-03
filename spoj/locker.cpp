/*
    Code by: KoKoDuDu
    Created: 2025.10.03 11:31:13
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

int mod_exp(int n, int x, int MOD = kMod) {
  int res = 1;
  while (x > 0) {
    if (x & 1) {
      res = (res * n) % MOD;
    }
    n = (n * n) % MOD;
    x >>= 1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;

  if (n <= 3) {
    cout << n << '\n';
    return;
  }

  if (n % 3 == 0) {
    cout << mod_exp(3, n / 3) << '\n';
  } else if (n % 3 == 1) {
    cout << (4 % kMod * mod_exp(3, (n - 4) / 3) % kMod) % kMod << '\n';
  } else {
    cout << (2 % kMod * mod_exp(3, (n - 2) / 3) % kMod) % kMod << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}