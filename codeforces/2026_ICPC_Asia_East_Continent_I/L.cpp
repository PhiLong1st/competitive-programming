/*
 Code by: Algorillas
 Created: 2026.09.14 23:09:09
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;
#define MAXLEN 1000010
using namespace std;
constexpr uint64_t mod = (1ULL << 61) - 1;
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);
uint64_t base_pow[MAXLEN];
int64_t modmul(uint64_t a, uint64_t b) {
  uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
  uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
  uint64_t ret =
      (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
  ret = (ret & mod) + (ret >> 61);
  ret = (ret & mod) + (ret >> 61);
  return ret - 1;
}

void init() {
  base_pow[0] = 1;
  for (int i = 1; i < MAXLEN; i++) {
    base_pow[i] = modmul(base_pow[i - 1], base);
  }
}

struct PolyHash {
  /// Remove suff vector and usage if reverse hash is not required for more
  /// speed
  vector<int64_t> pref, suff;
  PolyHash() {}
  template <typename T>
  PolyHash(const vector<T>& ar) {
    if (!base_pow[0]) init();
    int n = ar.size();
    assert(n < MAXLEN);
    pref.resize(n + 3, 0), suff.resize(n + 3, 0);
    for (int i = 1; i <= n; i++) {
      pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
      if (pref[i] >= mod) pref[i] -= mod;
    }
    for (int i = n; i >= 1; i--) {
      suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
      if (suff[i] >= mod) suff[i] -= mod;
    }
  }
  PolyHash(const char* str) : PolyHash(vector<char>(str, str + strlen(str))) {}
  uint64_t get_hash(int l, int r) {
    int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
    return h < 0 ? h + mod : h;
  }
  uint64_t rev_hash(int l, int r) {
    int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
    return h < 0 ? h + mod : h;
  }
  bool is_palindrome(int l, int r) { return get_hash(l, r) == rev_hash(l, r); }
};

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
      if (tl != tr) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
      }
      lazy[v] = 0;
    }
  }

  void update(int v, int tl, int tr, int l, int r, int val) {
    push(v, tl, tr);
    if (l > r) return;
    if (l == tl && r == tr) {
      lazy[v] += val;
      push(v, tl, tr);
      return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    push(2 * v, tl, tm);
    push(2 * v + 1, tm + 1, tr);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }

  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    push(v, tl, tr);
    if (l == tl && r == tr) return tree[v];
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, min(r, tm)) +
           query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
  }

  void update(int l, int r, int val) { update(1, 1, n, l, r, val); }

  int query(int l, int r) { return query(1, 1, n, l, r); }
};

void solve() {
  int n;
  cin >> n;

  vector<string> s(n + 1);
  for (int i = 1; i <= n; ++i) cin >> s[i];

  unordered_map<int, int> mp;

  vector<int> pos(n + 1), maxx(n + 1);
  for (int i = 1; i <= n; ++i) pos[i] = i;

  SegmentTree tree(n);

  for (int i = 1; i <= n; ++i) {
    PolyHash ph(s[i].c_str());

    for (int j = 0; j < s[i].size(); ++j) {
      int hash = ph.get_hash(0, j);
      int sz = j + 1;

      mp[hash]++;
      int cnt = mp[hash];

      if (maxx[cnt] < sz) {
        int l = pos[cnt], r = i - 1;
        int val = maxx[cnt] ^ cnt;
        tree.update(l, r, val);

        pos[cnt] = i;
        maxx[cnt] = sz;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (pos[i] == 0) continue;

    int l = pos[i], r = n;
    int val = maxx[i] ^ i;
    tree.update(l, r, val);
  }

  for (int i = 1; i <= n; ++i) cout << tree.query(i, i) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}