/*
    Code by: KoKoDuDu
    Created: 2025.10.19 11:50:20
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

static inline int cdiv(int a, int b) {
  return a >= 0 ? (a + b - 1) / b : a / b;
}

static inline int fdiv(int a, int b) {
  return a <= 0 ? (a - b + 1) / b : a / b;
}

static inline void add_mod(int& a, int b) {
  a = a + b;
  if (a >= kMod) a -= kMod;
}

static inline int mul_mod(int a, int b) {
  a = a * b % kMod;
  return a;
}

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> l, r;

  l.push_back(0);
  r.push_back(0);
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == '<') {
      l.push_back(i);
    } else {
      r.push_back(i);
    }
  }
  l.push_back(n + 1);
  r.push_back(n + 1);

  // for (auto& c : l) cout << c << ' ';
  // cout << '\n';
  // for (auto& c : r) cout << c << ' ';
  // cout << '\n';

  vector<int> pre_l((int)l.size()), pre_r((int)r.size());

  pre_l[0] = l[0];
  for (int i = 1; i < l.size(); ++i) pre_l[i] = pre_l[i - 1] + l[i];

  pre_r[0] = r[0];
  for (int i = 1; i < r.size(); ++i) pre_r[i] = pre_r[i - 1] + r[i];

  // for (auto& c : pre_l) cout << c << ' ';
  // cout << '\n';
  // for (auto& c : pre_r) cout << c << ' ';
  // cout << '\n';

  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == '<') {
      if (i == 1) {
        cout << 1 << ' ';
        continue;
      }
      int r_pos = upper_bound(r.begin(), r.end(), i) - r.begin() - 1;
      int l_pos = upper_bound(l.begin(), l.end(), i) - l.begin() - 1;

      int szL = (int)l.size() - l_pos;
      int szR = r_pos + 1;

      if (szR >= szL) {
        int sumR = 2 * (pre_r[r_pos] - pre_r[r_pos - szL + 1]);
        int sumL = 2 * (pre_l[l.size() - 1] - pre_l[l_pos - 1]) - l[l_pos] -
                   l[l.size() - 1];
        cout << sumL - sumR << ' ';
        // dbg(i, sumL, sumR, sumL - sumR);
      } else {
        int sumR = 2 * pre_r[r_pos];
        int sumL = 2 * (pre_l[l_pos + szR - 1] - pre_l[l_pos - 1]) - l[l_pos];
        cout << sumL - sumR << ' ';
        // dbg(i, sumL, sumR, sumL - sumR);
      }

      // dbg(szL, szR);
      // dbg(i, l[l_pos], r[r_pos]);
    } else {
      if (i == n) {
        cout << 1 << ' ';
        continue;
      }
      int r_pos = upper_bound(r.begin(), r.end(), i) - r.begin() - 1;
      int l_pos = upper_bound(l.begin(), l.end(), i) - l.begin();

      int szL = (int)l.size() - l_pos;
      int szR = r_pos + 1;

      if (szR > szL) {
        int sumR = 2 * (pre_r[r_pos] - pre_r[r_pos - szL]) - r[r_pos];
        int sumL =
            2 * (pre_l[l.size() - 1] - pre_l[l_pos - 1]) - l[l.size() - 1];

        cout << sumL - sumR << ' ';
        // dbg(i, sumL, sumR, sumL - sumR);
      } else {
        int sumR = 2 * pre_r[r_pos] - r[r_pos];
        int sumL = 2 * (pre_l[l_pos + szR - 2] - pre_l[l_pos - 1]);

        cout << sumL - sumR << ' ';
        // dbg(i, sumL, sumR, sumL - sumR);
      }

      // dbg(szL, szR);
      // dbg(i, l[l_pos], r[r_pos]);
    }
  }
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