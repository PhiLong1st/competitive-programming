/*
 Code by: Algorillas
 Created: 2026.09.05 16:45:17
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  if (a == b && a == 1) return void(cout << "no\n");
  if (a + b - 1 > n) return void(cout << "no\n");

  if (b == 1) {
    vector<int> ans(n + 1);
    ans[n] = n;

    int tmp = n - a + 1;
    for (int i = 1; i <= a - 1; ++i) ans[i] = tmp++;

    int cnt = 1;
    for (int i = a; i <= n - 1; ++i) ans[i] = cnt++;

    cout << "yes\n";
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << "\n";

    return;
  }

  vector<int> ans(n + 1);
  for (int i = 1; i <= a - 1; ++i) ans[i] = i;
  ans[a] = n;

  int tmp = n - 1;
  for (int i = n - b + 2; i <= n; ++i) ans[i] = tmp--;

  for (int i = a + 1; i < n - b + 2; ++i) ans[i] = a++;

  cout << "yes\n";
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}