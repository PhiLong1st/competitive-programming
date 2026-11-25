/*
 Code by: KoKoDuDu
 Created: 2026.10.26 22:50:54
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

void calc(string& s, string& t, int n, int m) {
  vector<int> lastW(n + 1);

  int posW = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'W')
      posW = i;
    else
      lastW[i] = posW;
  }

  vector<int> wInT;
  for (int i = 1; i <= m; ++i) {
    if (t[i] == 'R') continue;
    wInT.push_back(i);
  }

  vector<int> gaps;
  for (int j = 0; j + 1 < wInT.size(); ++j)
    gaps.push_back(wInT[j + 1] - wInT[j]);

  sort(gaps.begin(), gaps.end());

  int g = gaps.size();
  vector<int> pre(g + 1);
  for (int j = 0; j < g; ++j) pre[j + 1] = pre[j] + gaps[j];

  vector<int> ansS;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'W') continue;

    int sz = wInT.size();
    int temp = 0;

    if (lastW[i] >= 1) {
      if (sz == 0)
        temp = m + 1;
      else
        temp = max(m, wInT[sz - 1] + i - 1 - lastW[i]) + 1;
    } else {
      if (sz == 0) {
        temp = 1;
      } else {
        int idx = lower_bound(gaps.begin(), gaps.end(), i) - gaps.begin();
        temp = 1 + pre[idx] + (g - idx) * i + i;
      }
    }

    ansS.push_back(temp);
  }

  for (int& c : ansS) cout << c << ' ';
}

void solve() {
  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  s = " " + s, t = " " + t;

  calc(s, t, n, m);
  cout << '\n';

  calc(t, s, m, n);
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