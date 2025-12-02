/*
 Code by: KoKoDuDu
 Created: 2025.12.02 23:54:32
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

void solve() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int total = 0;
  for (char& c : s) total += (c == '1');

  auto f = [&](vector<int>& save) -> int {
    int sz = save.size();
    vector<int> pf(sz + 1);
    for (int i = 1; i <= sz; ++i) pf[i] = pf[i - 1] + save[i - 1];

    if (pf[sz] == 0) return total;

    int res = kMaxInf;
    int maxx = 0;
    for (int i = 1; i <= sz; ++i) {
      int val = i - 2 * pf[i];
      res = min(res, pf[sz] + val - maxx);
      maxx = max(maxx, val);
    }

    int bonus = sz != 0 ? pf[sz] : 0;
    return res + total - bonus;
  };

  int best = kMaxInf;
  for (int i = 0; i < k; ++i) {
    vector<int> save;
    for (int j = i; j < n; j += k) save.push_back((s[j] == '1'));
    best = min(best, f(save));
  }
  cout << best << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
/*
10 3
1001110101

0 3 6 9 
1 0 0 1 0 0 

*/