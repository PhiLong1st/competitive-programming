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

// sz state 2 3 5 7
int f[20][2][70][40][30][24][2];
map<int, int> cnt;
vector<int> num;

int calc_f(int sz, int state, bool has0, bool hasDif0, int s2, int s3, int s5,
           int s7) {
  // dbg(sz, state, has0, s2, s3, s5, s7, f[sz][state][s2][s3][s5][s7][has0]);

  if (sz == num.size()) {
    int val = (s2 >= cnt[2] && s3 >= cnt[3] && s5 >= cnt[5] && s7 >= cnt[7]) ||
              (hasDif0 && has0);

    // dbg(sz, state, has0, s2, s3, s5, s7, val);

    return f[sz][state][s2][s3][s5][s7][has0] = val;
  }

  if (f[sz][state][s2][s3][s5][s7][has0] != -1)
    return f[sz][state][s2][s3][s5][s7][has0];

  int ans = 0;
  int lim = state ? 9 : num[sz];

  for (int dg = 0; dg <= lim; ++dg) {
    int new_state = state ? state : (dg < num[sz]);
    int new_has0 = has0 ? has0 : (hasDif0 && dg == 0);
    int new_hasDif0 = hasDif0 ? hasDif0 : (dg != 0);

    if (dg == 0)
      ans += calc_f(sz + 1, new_state, new_has0, new_hasDif0, s2, s3, s5, s7);

    if (dg == 1)
      ans += calc_f(sz + 1, new_state, new_has0, new_hasDif0, s2, s3, s5, s7);

    if (dg == 2)
      ans +=
          calc_f(sz + 1, new_state, new_has0, new_hasDif0, s2 + 1, s3, s5, s7);

    if (dg == 3)
      ans +=
          calc_f(sz + 1, new_state, new_has0, new_hasDif0, s2, s3 + 1, s5, s7);

    if (dg == 4)
      ans +=
          calc_f(sz + 1, new_state, new_has0, new_hasDif0, s2 + 2, s3, s5, s7);

    if (dg == 5)
      ans +=
          calc_f(sz + 1, new_state, new_has0, new_hasDif0, s2, s3, s5 + 1, s7);

    if (dg == 6)
      ans += calc_f(sz + 1, new_state, new_has0, new_hasDif0, s2 + 1, s3 + 1,
                    s5, s7);

    if (dg == 7)
      ans +=
          calc_f(sz + 1, new_state, new_has0, new_hasDif0, s2, s3, s5, s7 + 1);

    if (dg == 8)
      ans +=
          calc_f(sz + 1, new_state, new_has0, new_hasDif0, s2 + 3, s3, s5, s7);

    if (dg == 9)
      ans +=
          calc_f(sz + 1, new_state, new_has0, new_hasDif0, s2, s3 + 2, s5, s7);
  }

  return f[sz][state][s2][s3][s5][s7][has0] = ans;
}

int calc(int x) {
  if (x == 0) return 0;

  memset(f, -1, sizeof(f));

  num.clear();
  int tmp = x;

  while (tmp > 0) {
    num.push_back(tmp % 10);
    tmp /= 10;
  }

  reverse(num.begin(), num.end());

  // dbg(x);
  // dbg(num);

  int res = calc_f(0, 0, 0, 0, 0, 0, 0, 0);

  // dbg(f[2][0][1][0][0][0][1]);  // 20
  // dbg(f[2][1][0][0][1][0][0]);  // 15
  // dbg(f[2][1][0][0][0][0][1]);  // 10
  // dbg(f[2][1][0][0][1][0][0]);  // 5

  return res;
}

void solve() {
  int k, l, r;
  cin >> k >> l >> r;

  int tmp = k;
  for (int i = 0; i < 4; ++i) {
    while (tmp % a[i] == 0) {
      tmp /= a[i];
      cnt[a[i]]++;
    }
  }

  // dbg(cnt);
  cout << calc(r) - calc(l - 1);
  // cout << calc(r) << ' ' << calc(l - 1) << ' ' << calc(r) - calc(l - 1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}