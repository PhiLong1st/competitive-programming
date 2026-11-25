/*
 Code by: KoKoDuDu
 Created: 2026.11.14 16:35:29
*/

#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second

using namespace std;

// const int MaxVal = 4e4 + 0307;
const int MaxVal = 5e3;
const int MaxX = 5e3;

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int& c : a) cin >> c;

  map<int, int> cntX, sumDiv;
  unordered_set<int> newA;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int sum = a[i] + a[j];
      cntX[sum]++;
      sumDiv[sum] = -1;
      newA.insert(sum);
    }
  }

  vector<int> primes, isPrimes(MaxVal + 1, 1);

  isPrimes[0] = isPrimes[1] = 0;
  for (int i = 2; i <= MaxVal; ++i) {
    if (!isPrimes[i]) continue;
    for (int j = i * i; j <= MaxVal; j += i) isPrimes[j] = 0;
  }

  for (int i = 2; i <= MaxVal; ++i) {
    if (!isPrimes[i]) continue;
    primes.push_back(i);
  }

  // cout << primes.size();
  // for (int& p : primes) cout << p << ' ';
  for (int i = 1; i <= )



  for (auto& x : newA) {
    int tmpX = x;

    if (sumDiv[x] != -1) continue;

    sumDiv[x] = 1;

    for (int& p : primes) {
      if (p > x) break;
      if (x % p != 0) continue;

      int cntP = 0;
      while (tmpX % p == 0) {
        tmpX /= p;
        ++cntP;
      }

      sumDiv[x] *= (fpow(p, cntP + 1) - 1) / (p - 1);
    }
  }

  int res = 0;
  
  for (auto& x : newA) {
    res += sumDiv[x] * cntX[x];
    // cerr << x << ' ' << sumDiv[x] << '\n';
  }

  cout << res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
