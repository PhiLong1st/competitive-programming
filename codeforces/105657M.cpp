/*
    Code by: KoKoDuDu
    Created: 2025.10.14 00:43:44
*/

#include <bits/stdc++.h>
#define int long long
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

struct SparseTable {
  const int LGMAX = 20;
  vector<vector<int>> spt;
  vector<int> arr;

  SparseTable(vector<int> arr) {
    this->arr = arr;
    spt.assign(LGMAX, vector<int>(arr.size()));
    build();
  }

  void build() {
    for (int i = 0; i < arr.size(); i++) spt[0][i] = arr[i];

    for (int bit = 1; bit < LGMAX; bit++) {
      for (int i = 0; i + (1 << (bit - 1)) < arr.size(); i++) {
        spt[bit][i] = gcd(spt[bit - 1][i], spt[bit - 1][i + (1 << (bit - 1))]);
      }
    }
  }

  int get_gcd(int l, int r) {
    if (l > r) return 0;
    int lg = 31 - __builtin_clz(r - l + 1);
    return gcd(spt[lg][l], spt[lg][r - (1 << lg) + 1]);
  }
};

void solve(vector<int>& a, int k) {
  int n = a.size();
  if (n == 1) return void(cout << k << ' ' << k * (k + 1) / 2 << '\n');

  vector<int> b;
  for (int i = 1; i < n; ++i) b.push_back(abs(a[i] - a[i - 1]));

  SparseTable spt(b);

  vector<int> l(n), r(n);
  stack<int> st;

  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] > a[i]) st.pop();
    if (st.empty()) {
      l[i] = 0;
    } else {
      l[i] = st.top() + 1;
    }

    st.push(i);
  }

  while (!st.empty()) st.pop();

  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && a[st.top()] > a[i]) st.pop();
    if (st.empty()) {
      r[i] = n - 1;
    } else {
      r[i] = st.top() - 1;
    }

    st.push(i);
  }

  int minn = *min_element(a.begin(), a.end());
  int cnt = 0, sum = 0;
  int t = spt.get_gcd(0, n - 2);

  auto calc = [&](int d) {
    int x = d - minn;
    if (x <= 0 || x > k) return;

    bool is_ok = true;
    for (int i = 0; i < n; ++i) {
      if (r[i] - l[i] == 0) continue;

      int g = spt.get_gcd(l[i], r[i] - 1);
      if (g % (a[i] + x) != 0) {
        is_ok = false;
        break;
      }
    }

    if (!is_ok) return;

    cnt++;
    sum += x;
  };

  for (int d = 1; d * d <= t; ++d) {
    if (t % d != 0) continue;
    calc(d);
    if (d * d != t) calc(t / d);
  }

  cout << cnt << ' ' << sum << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), save;
    for (auto& c : a) cin >> c;

    save.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i - 1]) continue;
      save.push_back(a[i]);
    }

    solve(save, k);
  }
  return 0;
}