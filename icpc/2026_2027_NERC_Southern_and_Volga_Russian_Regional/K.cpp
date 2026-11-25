/*
 Code by: Algorillas
 Created: 2026.11.24 15:48:06
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i <= 6; ++i) {
    if (i * 4 == n) return void(cout << i << ' ' << i << '\n');
  }

  for (int i = 1; i <= 6; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i == j) continue;
      if (i + j == n) return void(cout << i << ' ' << j << '\n');
    }
  }
  cout << 0 << ' ' << 0 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}