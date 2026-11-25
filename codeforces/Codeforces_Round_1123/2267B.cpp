/*
 Code by: KoKoDuDu
 Created: 2026.09.25 21:42:26
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
  int n;
  cin >> n;

  vector<int> a(n), save;
  map<int, int> mp, used;

  for (int& c : a) {
    cin >> c;

    if (mp[c] == 1) {
      save.push_back(c);
    }
  }

  sort(a.begin(), a.end(), greater<>());

  for (int& c : a) {
    mp[c]++;
    if (mp[c] == 1) save.push_back(c);
  }

  int x = 10;

  while (1) {
    int lim = -1;
    for (int i = 0; i < save.size(); ++i) {
      if (mp[save[i]] == 0) continue;

      lim = mp[save[i]];
      break;
    }

    if (lim == -1) {
      break;
    }

    for (int i = 0; i < save.size(); ++i) {
      if (mp[save[i]] == 0) continue;

      while (used[save[i]] < min(lim, mp[save[i]])) {
        used[save[i]]++;
        cout << save[i] << ' ';
      }
    }

    // cerr << lim << '\n';
    for (int i = 0; i < save.size(); ++i) {
      mp[save[i]] -= used[save[i]];
      used[save[i]] = 0;
      // cerr << save[i] << 'a' << mp[save[i]] << ' ';
    }
    // cerr << '\n';
  }
  cout << '\n';
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
