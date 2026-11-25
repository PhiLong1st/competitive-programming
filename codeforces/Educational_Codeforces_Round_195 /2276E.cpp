/*
 Code by: KoKoDuDu
 Created: 2026.10.14 23:25:31
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

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

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

struct Segment_Tree {
  vector<int> st;
  int n;
  Segment_Tree() {}
  Segment_Tree(int n) {
    this->n = n;
    st.assign(4 * n + 37, 0);
  }
  void update(int id, int l, int r, int pos, int val) {
    int mid = (l + r) >> 1;
    if (l == r) {
      st[id] = val;
      return;
    }
    if (pos <= mid) {
      update(id * 2, l, mid, pos, val);
    } else {
      update(id * 2 + 1, mid + 1, r, pos, val);
    }
    st[id] = st[id * 2] + st[id * 2 + 1];
  }
  int getSum(int id, int l, int r, int u, int v) {
    if (l > v || r < u) {
      return 0;
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    int s1 = getSum(id * 2, l, mid, u, v);
    int s2 = getSum(id * 2 + 1, mid + 1, r, u, v);
    return s1 + s2;
  }
};

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> f(n + 1);
  s = " " + s;

  string str = "";
  for (int i = n; i >= 3; --i) {
    string sub = s.substr(i - 3, 4);
    if (sub == "2025") {
      str += "a";
      f[i] = 1;
      f[i - 1] = f[i - 2] = f[i - 3] = -1;

      i -= 3;
    } else if (sub == "2026") {
      str += "b";
      f[i] = 2;
      f[i - 1] = f[i - 2] = f[i - 3] = -2;

      i -= 3;
    } else {
      str += s[i];
    }
  }

  for (int& c : f) cerr << c << ' ';

  vector<int> r25(n + 1), r26(n + 1);

  int p25 = n + 1, p26 = n + 1;
  for (int i = n; i >= 0; --i) {
    p25 = f[i] == 1 ? i : p25;
    p26 = f[i] == 2 ? i : p26;
    r25[i] = p25, r26[i] = p26;
  }

  Segment_Tree tree(n);

  for (int i = 0; i <= n; ++i) {
    if (f[i] == 0) {
      if (r25[i] < r26[i]) {
        // tree.update(1,1,n,r25[i],r26[i] - 1, 1);
      } else {
        // tree.update(1,1,n,r25[i],r26[i] - 1);
      }
    }

    if (f[i] == 1) {
        
    }
  }
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
