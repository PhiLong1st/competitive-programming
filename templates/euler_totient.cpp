#include <bits/stdc++.h>
using namespace std;

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