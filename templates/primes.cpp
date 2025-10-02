#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Primes {
  int n;
  vector<bool> is_prime;
  vector<int> primes;

  explicit Primes(int n) : n(n), is_prime(n + 1, true) {
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
      if (is_prime[i]) {
        primes.push_back(i);
        for (int j = i * i; j <= n; j += i) is_prime[j] = false;
      }
    }
  }

  vector<int> get_primes() const { return primes; }

  bool is_prime(long long x) const {
    if (0 <= x && x <= n) return is_prime[x];
    return MillerRabin(x);
  }

  long long next_prime(long long x) const {
    if (x <= n) {
      auto it = lower_bound(primes.begin(), primes.end(), x);
      return (it != primes.end() ? *it : -1);
    }
    while (!MillerRabin(x)) x++;
    return x;
  }

 private:
  static long long mod_mul(long long a, long long b, long long mod) {
    __int128 res = (__int128)a * b % mod;
    return (long long)res;
  }

  static long long mod_exp(long long b, long long e, long long mod) {
    long long res = 1 % mod;
    while (e > 0) {
      if (e & 1) res = mod_mul(res, b, mod);
      b = mod_mul(b, b, mod);
      e >>= 1;
    }
    return res;
  }

  static bool MillerRabin(long long n) {
    if (n < 2) return false;
    for (long long p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
      if (n % p == 0) return n == p;
    }

    int s = 0;
    long long d = n - 1;
    while ((d & 1) == 0) {
      d >>= 1;
      s++;
    }

    auto check = [&](long long a) {
      if (a % n == 0) return true;
      long long x = mod_exp(a, d, n);
      if (x == 1 || x == n - 1) return true;
      for (int i = 1; i < s; i++) {
        x = mod_mul(x, x, n);
        if (x == n - 1) return true;
      }
      return false;
    };

    for (long long a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
      if (!check(a)) return false;
    return true;
  }
};
