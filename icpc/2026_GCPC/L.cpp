/*
 Code by: Algorillas
 Created: 2026.11.09 20:35:22
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  string res = string(k, 'a');
  string p = "bcd";
  for (int i = k; i < n; ++i) {
    res += p[i % 3];
  }
  cout << res << '\n';
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