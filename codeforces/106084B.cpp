/*
    Code by: KoKoDuDu
    Created: 2025.09.27 13:41:33
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

  vector<int> isPrime(1000001, 1), sieve;
  isPrime[1] = 0;
  for (int i = 2; i <= 1000000; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= 1000000; j += i) {
        isPrime[j] = 0;
      }
    }
  }

  int t = 1;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;

    if (a > b) {
      swap(b, a);
    }

    if (a + 2 != b) {
      cout << "N\n";
      continue;
    }

    cout << ((isPrime[a] && isPrime[b]) ? "Y" : "N") << '\n';
  }

  return 0;
}