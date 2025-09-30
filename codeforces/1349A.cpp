/*
    Code by: KoKoDuDu
    Created: 2025.09.30 22:06:19
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

static inline int lcm(int x, int y) {
  int g = gcd(x, y);
  __int128 t = (__int128)((x / g)) * (y);
  return (int)(t);
}

void solve() {
  int n;

  cin >> n;
  vector<int> a(n), gcd_pre(n), gcd_suf(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    gcd_pre[i] = (i == 0) ? a[i] : __gcd(gcd_pre[i - 1], a[i]);
  }

  for (int i = n - 1; i >= 0; --i) {
    gcd_suf[i] = (i == n - 1) ? a[i] : __gcd(gcd_suf[i + 1], a[i]);
  }

  // for (int i = 0; i < n; ++i) {
  //   cerr << i << ' ' << gcd_pre[i] << ' ' << gcd_suf[i] << '\n';
  // }

  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      ans = lcm(ans, gcd_suf[i + 1]);
    } else if (i == n - 1) {
      ans = lcm(ans, gcd_pre[i - 1]);
    } else {
      ans = lcm(ans, __gcd(gcd_pre[i - 1], gcd_suf[i + 1]));
    }
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