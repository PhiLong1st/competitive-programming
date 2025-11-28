/*
 Code by: KoKoDuDu
 Created: 2025.11.28 10:35:13
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

int add_mod(int a, int b) { return a + b >= kMod ? a + b - kMod : a + b; }

int minus_mod(int a, int b) { return (a - b + kMod) % kMod; }

int mul_mod(int a, int b) { return a * b % kMod; }

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

bool cmp(string s, string t) {
  int n = s.size(), m = t.size();
  if (n != m) return n < m;

  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) return s[i] < t[i];
  }
  return 0;
}

void solve() {
  int n;
  string s;
  cin >> n >> s;

  for (int i = 1; i < n; ++i) {
    string s1 = s.substr(0, i);
    string s2 = s.substr(i, n - i);
    if (cmp(s1, s2)) {
      cout << "YES\n";
      cout << "2\n";
      cout << s1 << ' ' << s2 << '\n';
      return;
    }
  }
  cout << "NO\n";
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
