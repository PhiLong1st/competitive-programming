/*
 Code by: Algorillas
 Created: 2026.11.24 17:50:45
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

  vector<int> c(n);
  for (int& x : c) cin >> x;

  string s;
  cin >> s;

  int ans = -1;
  vector<int> x(n);

  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      if (j != (s[0] - '0')) continue;

      x[0] = i, x[1] = j;

      for (int i = 2; i < n; i++) x[i] = x[i - 2] ^ (s[i - 1] - '0');

      if (x[n - 2] != (s[n - 1] - '0')) continue;

      int tmp = 0;
      for (int k = 0; k < n; k++) tmp += x[k] ? c[k] : 0;

      ans = max(ans, tmp);
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

/*
s[i] = 1
-> f[i - 1] = 0, f[i + 1] = 1
-> f[i - 1] = 1, f[i + 1] = 0

s[i] = 0
-> f[i - 1] = 1, f[i + 1] = 1
-> f[i - 1] = 0, f[i + 1] = 0

f[i - 1] ^ f[i + 1] = s[i]
-> f[i + 1] = s[i] ^ f[i - 1]

2
10 20
s: 01
f: 01
x: 10

3
10 20 30
s: 111
f: 111
x: 011
*/