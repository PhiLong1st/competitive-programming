/*
    Code by: KoKoDuDu
    Created: 2025.10.03 11:43:30
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e7 + 7;
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
  int n, k;
  while (cin >> n >> k) {
    if (n == 0 && k == 0) {
      return;
    }

    cout << ((2 * mod_exp(n - 1, n - 1) % kMod + mod_exp(n, n)) % kMod +
             (2 * mod_exp(n - 1, k) % kMod + mod_exp(n, k)) % kMod) %
                kMod
         << '\n';
  }
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