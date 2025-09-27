#include <bits/stdc++.h>
using namespace std;

/**
 * Sieve Euler's totient φ(k) for all k in [0..n].
 */
vector<int> sieve_totients(int n) {
  vector<int> phi(n + 1);
  iota(phi.begin(), phi.end(), 0);

  for (int p = 2; p <= n; ++p) {
    if (phi[p] == p) {
      for (int k = p; k <= n; k += p) {
        phi[k] -= phi[k] / p;
      }
    }
  }

  return phi;
}

/**
 * Sieve the sum of numbers in [1..k] that are coprime with k, for all k in
 * [0..n].
 */
vector<long long> sieve_coprime_sums(int n) {
  vector<int> phi = sieve_totients(n);
  vector<long long> sum_coprime(n + 1, 0);

  if (n >= 1) sum_coprime[1] = 1;

  for (int k = 2; k <= n; ++k) {
    sum_coprime[k] = 1LL * k * phi[k] / 2;
  }

  return sum_coprime;
}