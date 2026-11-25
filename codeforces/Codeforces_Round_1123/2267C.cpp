/*
 Code by: KoKoDuDu
 Created: 2026.09.25 22:07:32
*/

#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second

using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

void add_mod(int& a, int b) { a = a + b >= kMod ? a + b - kMod : a + b; }

void minus_mod(int& a, int b) { a = (a - b + kMod) % kMod; }

void mul_mod(int& a, int b) { a = a * b % kMod; }

void maximize(int& x, int y) { x = max(x, y); }

void minimize(int& x, int y) { x = min(x, y); }

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res;
}

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

vector<int> primes;

void solve() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int& i : a) cin >> i;

  if (x == 1) return void(cout << 0 << '\n');

  vector<int> save;

  map<int, int> mp;

  for (int& p : primes) {
    if (p > x) break;
    if (x % p == 0) save.push_back(p);
    while (x % p == 0) x /= p;
  }

  for (int& i : a) {
    for (int& p : save) {
      if (i % p == 0) mp[p] += i;
    }
  }

  int res = 0;
  for (int& p : save) res = max(res, mp[p]);
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<bool> isPrime(300011, true);

  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i <= 300010; ++i) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j <= 300010; j += i) isPrime[j] = false;
  }

  for (int i = 2; i <= 300010; ++i) {
    if (!isPrime[i]) continue;
    primes.push_back(i);
  }

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
