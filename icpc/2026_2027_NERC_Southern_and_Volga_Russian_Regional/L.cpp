/*
 Code by: Algorillas
 Created: 2026.11.24 19:05:33
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pii pair<int, int>

vector<int> primes;

void solve() {
  int n;
  cin >> n;

  int t = sqrt(n);
  if (t * t == n) return void(cout << n << ' ' << 1LL * n * n << '\n');

  int tmpN = n;
  for (int& p : primes) {
    int p2 = p * p;

    if (p2 > tmpN) break;

    if (tmpN % p) continue;

    tmpN /= p;
    if (tmpN % p == 0)
      return void(cout << 1LL * (n / p) * (n / p) << ' ' << 1LL * n * n
                       << '\n');

    int t = sqrt(tmpN);
    if (t > 1 && t * t == tmpN)
      return void(cout << 1LL * (n / t) * (n / t) << ' ' << 1LL * n * n << '\n');
  }

  cout << "0 0\n";
}

void prepare() {
  int maxN = 1374;
  vector<int> isPrime(maxN + 1, 1);

  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i <= maxN; ++i) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j <= maxN; j += i) isPrime[j] = 0;
  }

  for (int i = 2; i <= maxN; ++i) {
    if (!isPrime[i]) continue;
    primes.push_back(i);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  prepare();

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}