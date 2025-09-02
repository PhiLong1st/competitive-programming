/*
    Code by: KoKoDuDu
    Created: 2025.09.01 23:58:08
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;
const int kMaxN = 1e5 + 10;

void solve() {
  int n;
  cin >> n;

  vector<int> coprime_numbers(kMaxN);

  int cnt = 1;
  int product_mod_n = 1;

  for (int i = 1; i < n; ++i) {
    if (__gcd(i, n) == 1) {
      coprime_numbers[cnt++] = i;
      product_mod_n = (product_mod_n * i) % n;
    }
  }

  int output_count = (product_mod_n != 1) ? cnt - 2 : cnt - 1;
  cout << output_count << '\n';

  for (int i = 1; i < cnt; ++i) {
    if (product_mod_n != 1 && coprime_numbers[i] == product_mod_n) {
      continue;
    }
    cout << coprime_numbers[i] << ' ';
  }
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