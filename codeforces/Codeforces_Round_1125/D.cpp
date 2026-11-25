/*
 Code by: KoKoDuDu
 Created: 2026.10.07 22:54:35
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

  vector<int> a(n), b(n), c(n);
  int minn = kMaxInf, maxx = kMinInf;

  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    minn = min(minn, a[i] + b[i] + c[i]);
    maxx = max(maxx, a[i] + b[i] + c[i]);
  }

  int l = minn, r = maxx + k;
  int res = l;

  while (l <= r) {
    int mid = (l + r) / 2;
    int cnt = k;
    bool isOk = true;

    for (int i = 0; i < n; ++i) {
      int sum = a[i] + b[i] + c[i];
      if (sum >= mid) continue;

      if (a[i] == b[i] && b[i] == c[i]) {
        isOk = false;
        break;
      }

      int cost = kMaxInf;

      bool canInc = a[i] > b[i] || a[i] > c[i] || b[i] > c[i];
      if (!canInc) {
        // a > b -> 1
        // a > c -> 1
        // b > c -> 1

        // a < b && a <= c && b < c -> a <= b <= c
        cost = (a[i] == b[i]) ? min(cost, b[i] - a[i]) + 1
                              : min({b[i] - a[i], c[i] - b[i]}) + 1;

        if (cost > cnt) {
          isOk = false;
          break;
        }

        cnt -= cost;

        cost = mid - (sum - cost);
        if (cost > cnt) {
          isOk = false;
          break;
        }

        cnt -= cost;
        
      } else {
        cost = mid - sum;

        if (cost > cnt) {
          isOk = false;
          break;
        }

        cnt -= cost;
      }
    }

    if (isOk) {
      res = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << res << '\n';
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
