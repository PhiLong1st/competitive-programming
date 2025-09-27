/*
    Code by: KoKoDuDu
    Created: 2025.09.27 18:27:05
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i != 0) {
      continue;
    }

    int cnt_pow = 0;
    while (n % i == 0) {
      cnt_pow++;
      n /= i;
    }

    int total = 0;
    for (int j = 1; total + j <= cnt_pow; ++j) {
      ans++;
      total += j;
    }
  }

  if (n != 1) {
    ans++;
  }

  cout << ans;
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