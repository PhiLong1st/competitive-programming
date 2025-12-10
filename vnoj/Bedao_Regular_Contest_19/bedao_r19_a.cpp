#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
  int x, k;
  cin >> x >> k;

  int g = __gcd(x, k);
  if (g == 1) {
    cout << k;
  } else {
    cout << k / g;
  }
}
