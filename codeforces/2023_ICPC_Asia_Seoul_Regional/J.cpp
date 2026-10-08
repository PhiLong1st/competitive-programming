/*
 Code by: Algorillas
 Created: 2026.09.17 21:03:21
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

int a[4] = {2, 3, 5, 7};

// exponent of 2, 3, 5, 7 contributed by each digit
int e[10][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0},
                {2, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1},
                {3, 0, 0, 0}, {0, 2, 0, 0}};

int cnt[4];  // exponent of 2, 3, 5, 7 in k
bool bad;    // k has a prime factor > 7 -> only numbers containing 0 work
int pw10[30];

// sz mode(0: not started, 1: started w/o 0, 2: has 0) s2 s3 s5 s7
// only memoized when state == 1 (free), s2..s7 are capped at cnt
vector<int> f;
vector<int> num;

int id(int sz, int mode, int s2, int s3, int s5, int s7) {
  int r = sz * 3 + mode;
  r = r * (cnt[0] + 1) + s2;
  r = r * (cnt[1] + 1) + s3;
  r = r * (cnt[2] + 1) + s5;
  r = r * (cnt[3] + 1) + s7;
  return r;
}

int calc_f(int sz, int state, bool has0, bool hasDif0, int s2, int s3, int s5,
           int s7) {
  if (sz == sz(num)) {
    bool ok = s2 == cnt[0] && s3 == cnt[1] && s5 == cnt[2] && s7 == cnt[3];
    return hasDif0 && (has0 || (ok && !bad));
  }

  int mode = hasDif0 + has0;  // has0 implies hasDif0

  // already contains a 0 and is free: every suffix is fine
  if (state && has0) return pw10[sz(num) - sz];

  int key = id(sz, mode, s2, s3, s5, s7);
  if (state && f[key] != -1) return f[key];

  int ans = 0;
  int lim = state ? 9 : num[sz];

  for (int dg = 0; dg <= lim; ++dg) {
    int new_state = state ? state : (dg < num[sz]);
    int new_has0 = has0 ? has0 : (hasDif0 && dg == 0);
    int new_hasDif0 = hasDif0 ? hasDif0 : (dg != 0);

    int n2 = min(cnt[0], s2 + e[dg][0]);
    int n3 = min(cnt[1], s3 + e[dg][1]);
    int n5 = min(cnt[2], s5 + e[dg][2]);
    int n7 = min(cnt[3], s7 + e[dg][3]);

    ans += calc_f(sz + 1, new_state, new_has0, new_hasDif0, n2, n3, n5, n7);
    ans %= MOD;
  }

  if (state) f[key] = ans;
  return ans;
}

int calc(string x) {
  // strip leading zeros
  int p = 0;
  while (p < sz(x) && x[p] == '0') ++p;
  x = x.substr(p);

  if (x.empty()) return 0;

  num.clear();
  for (char ch : x) num.push_back(ch - '0');

  f.assign((sz(num) + 1) * 3 * (cnt[0] + 1) * (cnt[1] + 1) * (cnt[2] + 1) *
               (cnt[3] + 1),
           -1);

  return calc_f(0, 0, 0, 0, 0, 0, 0, 0);
}

// x - 1 on a decimal string (x >= 1)
string dec(string x) {
  int i = sz(x) - 1;
  while (x[i] == '0') x[i--] = '9';
  --x[i];
  return x;
}

void solve() {
  int k;
  string l, r;
  cin >> k >> l >> r;

  for (int i = 0; i < 4; ++i) {
    while (k % a[i] == 0) {
      k /= a[i];
      cnt[i]++;
    }
  }
  bad = k != 1;

  pw10[0] = 1;
  for (int i = 1; i < 30; ++i) pw10[i] = pw10[i - 1] * 10 % MOD;

  // dbg(cnt);
  cout << ((calc(r) - calc(dec(l))) % MOD + MOD) % MOD;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
