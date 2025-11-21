/*
    Code by: KoKoDuDu
    Created: 2025.11.17 23:13:36
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
#define el '\n'

using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 30;
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

void solve() {
  auto ask = [&](int a, int b) -> int {
    cout << "? " << a << ' ' << b << '\n';
    cout.flush();

    int rem;
    cin >> rem;
    return rem;
  };

  int first_bit = 0;
  int res = 0, mask = 0;

  for (int bit = 1; bit < kMaxBit; ++bit) {
    int a = (1LL << kMaxBit);
    int b = a - (1LL << bit);
    int rem = ask(a, b);
    if (rem != (1LL << bit)) break;

    first_bit = bit;
  }

  res = (1LL << first_bit);
  mask = (1LL << first_bit);

  // cerr << "first_bit: " << first_bit << '\n';
  // cerr << "res: " << res << '\n';
  // cerr << "mask: " << mask << '\n';

  for (int bit = first_bit + 1; bit < kMaxBit; ++bit) {
    int a = (1LL << kMaxBit) + mask;
    int b = a - (1LL << (bit + 1));
    int rem = ask(a, b);
    if (rem == (1LL << (bit + 1))) {
      res += (1LL << bit);
    } else {
      mask += (1LL << bit);
    }
    // cerr << "res: " << res << '\n';
    // cerr << "mask: " << mask << '\n';
  }

  cout << "! " << res << '\n';
  cout.flush();
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