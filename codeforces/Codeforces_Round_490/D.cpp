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
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int& c : a) cin >> c;

  vector<int> mp(m, 0);
  vector<vector<int>> save(m);
  for (int i = 0; i < n; ++i) save[a[i] % m].push_back(i), mp[a[i] % m]++;

  int cost = 0;
  int sz = n / m;
  vector<pii> temp;

  for (int t = 0; t < 2 * m; ++t) {
    int r = t % m;

    while (mp[r] < sz && !temp.empty()) {
      pii cur = temp.back();
      temp.pop_back();
      a[cur.fi] += t - cur.se;
      cost += t - cur.se;
      mp[r]++;
    }

    if (t < m) {
      while (mp[r] > sz) {
        temp.push_back({save[r].back(), t});
        save[r].pop_back();
        mp[r]--;
      }
    }
  }

  cout << cost << '\n';
  for (int& c : a) cout << c << ' ';
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}