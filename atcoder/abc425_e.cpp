/*
    Code by: KoKoDuDu
    Created: 2025.09.27 19:28:05
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

const int MAXN = 1e6;
long long fac[MAXN + 1];
long long inv[MAXN + 1];

int MOD = 1e9 + 7;

const int N = 5007;
int C[N][N];

void prepare() {
  C[0][0] = 1;
  for (int n = 1; n < N; ++n) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k) C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
  }
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  int total = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    total += a[i];
  }

  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans *= C[total][a[i]];
    ans %= MOD;
    total -= a[i];
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  cin >> MOD;
  prepare();
  while (t--) {
    solve();
  }

  return 0;
}