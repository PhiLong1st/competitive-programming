/*
    Code by: KoKoDuDu
    Created: 2025.09.07 22:12:57
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), f(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  vector<int> save;
  for (int i = 1; i <= n; ++i) {
    while (!save.empty() && a[save.back()] < a[i]) {
      save.pop_back();
    }
    if (a[i] == b[i]) {
      f[i] = i;
    } else {
      int l = 0, r = save.size() - 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[save[mid]] >= b[i]) {
          f[i] = save[mid];
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
    save.push_back(i);
  }

  for (int i = 1; i <= n; ++i) {
    ans += f[i] * (n - i + 1);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("2137F.inp", "r", stdin);
  // freopen("2137F.out", "w", stdout);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}