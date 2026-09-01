/*
 Code by: KoKoDuDu
 Created: 2026.06.12 22:03:18
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

  vector<int> a(n);
  for (int& c : a) cin >> c;

  if (n == 1) {
    cout << "NO\n";
    return;
  }

  sort(a.begin(), a.end());

  vector<int> save;
  save.push_back(a[0]);

  map<int, int> mp;
  for (int& c : a) mp[c]++;

  for (int i = 0; i < n - 1; ++i) {
    if (a[i] == a[i + 1]) continue;
    save.push_back(a[i + 1]);
  }

  // for (int& c : save) cout << c << ' ';

  for (int i = save.size() - 1; i >= 0; --i) {
    int x = save[i];
    if (mp[x] % 2 == 0) {
      cout << "YES\n";
      return;
    }

    if (i == 0) continue;

    int y = save[i - 1];
    if (y + k >= x) {
      cout << "YES\n";
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
