/*
    Code by: KoKoDuDu
    Created: 2025.10.18 10:06:10
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

  vector<int> a(n);
  for (auto& c : a) cin >> c;

  vector<int> min_l(n), min_r(n), max_l(n), max_r(n);
  stack<int> min_st, max_st;

  for (int i = 0; i < n; ++i) {
    while (!min_st.empty() && a[min_st.top()] > a[i]) min_st.pop();
    min_l[i] = min_st.empty() ? 0 : min_st.top() + 1;
    min_st.push(i);

    while (!max_st.empty() && a[max_st.top()] < a[i]) max_st.pop();
    max_l[i] = max_st.empty() ? 0 : max_st.top() + 1;
    max_st.push(i);
  }

  while (!min_st.empty()) min_st.pop();
  while (!max_st.empty()) max_st.pop();

  for (int i = n - 1; i >= 0; --i) {
    while (!min_st.empty() && a[min_st.top()] >= a[i]) min_st.pop();
    min_r[i] = min_st.empty() ? n - 1 : min_st.top() - 1;
    min_st.push(i);

    while (!max_st.empty() && a[max_st.top()] <= a[i]) max_st.pop();
    max_r[i] = max_st.empty() ? n - 1 : max_st.top() - 1;
    max_st.push(i);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    // dbg(i, min_l[i], min_r[i], max_l[i], max_r[i]);
    ans -= a[i] * (i - min_l[i] + 1) * (min_r[i] - i + 1);
    ans += a[i] * (i - max_l[i] + 1) * (max_r[i] - i + 1);
    // dbg(i - min_l[i] + 1, min_r[i] - i + 1, i - max_l[i] + 1, max_r[i] - i +
    // 1);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}