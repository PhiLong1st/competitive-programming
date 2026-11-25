/*
 Code by: Algorillas
 Created: 2026.11.24 16:25:24
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int a = n / k, b = m / k;
  int ans = 2 * a * b;
  if (n % k == k - 1 && m % k == k - 1) ans += min(a, b);
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
// 5 5 3  - 2