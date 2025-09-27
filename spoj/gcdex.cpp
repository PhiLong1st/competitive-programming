/*
    Code by: KoKoDuDu
    Created: 2025.09.27 10:39:48
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

vector<int> get_euler_totient(int n) {
  vector<int> phi(n + 1);

  iota(phi.begin(), phi.end(), 0);

  for (int i = 2; i <= n; ++i) {
    if (phi[i] != i) {
      continue;
    }

    for (int j = i; j <= n; j += i) {
      phi[j] -= phi[j] / i;
    }
  }

  return phi;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> phi = get_euler_totient(1000000);
  vector<int> ans(1000001);

  for (int i = 2; i <= 1000000; ++i) {
    ans[i] += ans[i - 1] + phi[i];
    for (int j = i * 2; j <= 1000000; j += i) {
      ans[j] += phi[j / i] * i;
    }
  }

  int x;
  while (cin >> x) {
    if (x == 0) {
      return 0;
    }

    cout << ans[x] << '\n';
  }

  return 0;
}