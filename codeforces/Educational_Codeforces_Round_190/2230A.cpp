/*
 Code by: KoKoDuDu
 Created: 2026.05.27 10:10:08
*/

#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second

using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  if (3 * a <= b) {
    cout << n * a << '\n';
    return;
  }

  cout << (n / 3) * b + min(a * (n % 3), b) << '\n';
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
