/*
 Code by: KoKoDuDu
 Created: 2025.11.29 16:40:49
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

struct SegmentTree {
  vector<int> tree, lazy;
  int n;

  SegmentTree(int size) {
    n = size;
    tree.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
  }

  void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
      tree[v] += lazy[v] * (tr - tl + 1);
      tree[v] %= kMod;
      if (tl != tr) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v] %= kMod;
        lazy[2 * v + 1] += lazy[v];
        lazy[2 * v + 1] %= kMod;
      }
      lazy[v] = 0;
    }
  }

  void update(int v, int tl, int tr, int l, int r, int val) {
    push(v, tl, tr);
    if (l > r) return;
    if (l == tl && r == tr) {
      lazy[v] = (lazy[v] + val) % kMod;
      push(v, tl, tr);
      return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    push(2 * v, tl, tm);
    push(2 * v + 1, tm + 1, tr);
    tree[v] = (tree[2 * v] + tree[2 * v + 1]) % kMod;
  }

  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    push(v, tl, tr);
    if (l == tl && r == tr) return tree[v];
    int tm = (tl + tr) / 2;
    int L = query(2 * v, tl, tm, l, min(r, tm));
    int R = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return (L + R) % kMod;
  }

  void update(int l, int r, int val) { update(1, 1, n, l, r, val); }

  int query(int l, int r) { return query(1, 1, n, l, r); }
};

pii convert_to_frac(string& s) {
  int x = 0, y = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '.') break;
    y = y * 10;
  }

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') continue;
    x = x * 10 + (s[i] - '0');
  }
  return {x, y};
};

void norm(int& p, int& q) {
  int _g = gcd(p, q);
  p /= _g;
  q /= _g;
}

void solve() {
  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  auto [num, dem] = convert_to_frac(s);
  int a = dem - num;
  int b = dem;

  norm(a, b);
  int a_b = a * fpow(b, kMod - 2) % kMod;
  int b_a = b * fpow(a, kMod - 2) % kMod;

  vector<int> a_div_b(n + 1), b_div_a(n + 1);
  a_div_b[0] = 1;
  b_div_a[0] = 1;
  for (int i = 1; i <= n; i++) {
    a_div_b[i] = a_div_b[i - 1] * a_b % kMod;
    b_div_a[i] = b_div_a[i - 1] * b_a % kMod;
  }

  SegmentTree fwd(n);
  SegmentTree rev(n);

  while (q--) {
    char type;
    cin >> type;
    if (type == '+') {
      int x, pos;
      cin >> x >> pos;
      int val = x * a_div_b[pos] % kMod;
      fwd.update(pos, pos, val);

      int rev_pos = n - pos + 1;
      val = x * a_div_b[rev_pos] % kMod;
      rev.update(rev_pos, rev_pos, val);
    } else if (type == '-') {
      int x, pos;
      cin >> x >> pos;
      int val = x * a_div_b[pos] % kMod;
      val = (-val + kMod) % kMod;
      fwd.update(pos, pos, val);

      int rev_pos = n - pos + 1;
      val = x * a_div_b[rev_pos] % kMod;
      val = (-val + kMod) % kMod;
      rev.update(rev_pos, rev_pos, val);
    } else {
      int id;
      cin >> id;
      int s1 = fwd.query(id, n);

      int rev_id = n - id + 1;
      int s2 = rev.query(rev_id + 1, n);

      s1 = s1 * b_div_a[id] % kMod;
      s2 = s2 * b_div_a[rev_id] % kMod;
      cout << (s1 + s2) % kMod << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
