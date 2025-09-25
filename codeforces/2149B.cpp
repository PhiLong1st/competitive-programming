/*
    Code by: KoKoDuDu
    Created: 2025.09.25 21:48:39
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& c : a) {
    cin >> c;
  }

  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = 1; i < n; i += 2) {
    ans = max(ans, a[i] - a[i - 1]);
  }

  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}