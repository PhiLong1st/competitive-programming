/*
 Code by: KoKoDuDu
 Created: 2026.10.07 23:46:25
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
const int kMaxN = 1e6 + 0307;
const int kMod = (1ll << 61) - 1;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;
const int kBase = 37;

int d[kMaxN + 17], pw[kMaxN + 17], idx[kMaxN + 17], hashX[kMaxN + 17];
vector<int> primes;
vector<vector<int>> normX(kMaxN + 17);

int mulmod(int a, int b) {
  __uint128_t t = (__uint128_t)a * b;
  int r = (int)(t & kMod) + (int)(t >> 61);
  return r >= kMod ? r - kMod : r;
}

int addmod(int a, int b) {
  int r = a + b;
  return r >= kMod ? r - kMod : r;
}

struct Segment_Tree {
  vector<int> st;
  int n;

  Segment_Tree() {}

  Segment_Tree(int n) {
    this->n = n;
    st.assign(4 * n + 37, 0);
  }

  void update(int id, int l, int r, int pos) {
    int mid = (l + r) >> 1;

    if (l == r) {
      st[id] = 1 - st[id];
      return;
    }

    if (pos <= mid) {
      update(id * 2, l, mid, pos);
    } else {
      update(id * 2 + 1, mid + 1, r, pos);
    }

    int sz = mid - l + 1;
    st[id] = addmod(st[id * 2], mulmod(pw[sz], st[id * 2 + 1]));
  }

  int getSum(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;

    if (u <= l && r <= v) return st[id];

    int mid = (l + r) >> 1;
    int s1 = getSum(id * 2, l, mid, u, v);
    int s2 = getSum(id * 2 + 1, mid + 1, r, u, v);

    int sz = mid - l + 1;
    return addmod(s1, mulmod(pw[sz], s2));
  }
};

Segment_Tree tree;
int m;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) cin >> x;

  unordered_map<int, int> freq;
  for (int& x : a) freq[hashX[x]]++;

  int res = 0;

  for (int j = 0; j < n; j++) {
    for (int& p : normX[a[j]]) tree.update(1, 1, m, idx[p]);
    int hashMul = tree.getSum(1, 1, m, 1, m);
    res += freq[hashMul];
  }

  for (int j = 0; j < n; j++) {
    for (int& p : normX[a[j]]) tree.update(1, 1, m, idx[p]);
  }

  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  for (int i = 1; i <= kMaxN; ++i) d[i] = i;

  for (int p = 2; p * p <= kMaxN; ++p) {
    if (d[p] != p) continue;
    for (int j = p * p; j <= kMaxN; j += p) {
      if (d[j] == j) d[j] = p;
    }
  }

  for (int p = 2; p <= kMaxN; ++p) {
    if (d[p] != p) continue;
    primes.push_back(p);
    idx[p] = primes.size();
  }

  m = primes.size();

  pw[0] = 1;
  for (int i = 1; i <= kMaxN; ++i) pw[i] = mulmod(pw[i - 1], kBase);

  for (int x = 1; x <= kMaxN; ++x) {
    int tmpX = x;

    while (tmpX > 1) {
      int p = d[tmpX], cnt = 0;
      while (tmpX % p == 0) {
        tmpX /= p;
        cnt++;
      }

      if (cnt % 2) normX[x].push_back(p);
    }

    for (int& p : normX[x]) hashX[x] = addmod(hashX[x], pw[idx[p] - 1]);
  }

  tree = Segment_Tree(m);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}