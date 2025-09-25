/*
    Code by: KoKoDuDu
    Created: 2025.09.25 21:36:18
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
  int num_negative = 0, num_zero = 0;
  for (auto& c : a) {
    cin >> c;
    num_negative += c < 0;
    num_zero += c == 0;
  }

  cout << 2 * (num_negative % 2) + num_zero << '\n';
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