/*
    Code by: KoKoDuDu
    Created: 17.02.2025 13:46:27
    Link: https://codeforces.com/problemset/problem/1611/C
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (a[1] == n || a[n] == n) {
    if (a[1] == n) {
      cout << a[1] << ' ';
      for (int i = n; i >= 2; --i) {
        cout << a[i] << ' ';
      }
    } else {
      for (int i = n - 1; i >= 1; --i) {
        cout << a[i] << ' ';
      }
      cout << a[n] << ' ';
    }
    cout << '\n';
  } else {
    cout << -1 << '\n';
  }
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