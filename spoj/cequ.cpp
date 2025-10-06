/*
    Code by: KoKoDuDu
    Created: 2025.10.07 02:03:27
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    int g = __gcd(a, b);
    cout << "Case " << i << ": " << (c % g == 0 ? "Yes" : "No") << "\n";
  }

  return 0;
}