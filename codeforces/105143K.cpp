/*
    Code by: KoKoDuDu
    Created: 2025.10.09 22:38:41
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

void solve() {
  int n;
  cin >> n;

  if (n % 4 == 0) return void(cout << "Fluttershy\n");
  if (n % 4 == 1) return void(cout << "Fluttershy\n");
  if (n % 4 == 2) return void(cout << "Pinkie Pie\n");
  if (n % 4 == 3) return void(cout << "Pinkie Pie\n");
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