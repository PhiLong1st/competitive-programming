/*
    Code by: KoKoDuDu
    Created: 2025.10.03 01:20:05
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;

  if (b == 0) {
    cout << 1 << '\n';
    return;
  }

  int last_digit = a % 10;
  vector<int> cycle;

  int temp = last_digit;
  do {
    cycle.push_back(temp);
    temp = (temp * last_digit) % 10;
  } while (temp != last_digit);

  int pos = (b - 1) % cycle.size();
  cout << cycle[pos] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}