/*
    Code by: KoKoDuDu
    Created: 2025.10.28 21:37:55
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e6 + 0307;
const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

vector<int> primes;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& x : a) cin >> x;

  int ans = kMaxInf;
  for (auto& x : a) {
    for (auto& p : primes) {
      if (x % p != 0) {
        ans = min(ans, p);
        break;
      }
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<bool> is_prime(kMaxN + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= kMaxN; ++i) {
    if (!is_prime[i]) continue;
    for (int j = i * i; j <= kMaxN; j += i) is_prime[j] = false;
  }

  for (int i = 2; i <= kMaxN; ++i) {
    if (is_prime[i]) primes.push_back(i);
  }

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}