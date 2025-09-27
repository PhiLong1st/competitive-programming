/*
    Code by: KoKoDuDu
    Created: 2025.09.27 11:32:02
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

vector<int> get_euler_totient_sum(int n) {
  vector<int> ans(n + 1);
  vector<int> phi = get_euler_totient(n);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      ans[j] += phi[i] * i;
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> sum = get_euler_totient_sum(1000000);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << n * (sum[n] / 2 + 1) << '\n';
  }

  return 0;
}