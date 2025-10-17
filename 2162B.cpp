/*
    Code by: KoKoDuDu
    Created: 2025.10.17 22:21:37
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

  auto isPalindrome = [&](const string& str) {
    int l = 0, r = (int)str.size() - 1;
    while (l < r) {
      if (str[l] != str[r]) return false;
      l++;
      r--;
    }
    return true;
  };

  auto isIncMask = [&](int mask) {
    char pre = -1;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        if (pre != -1 && s[i] < pre) return false;
        pre = s[i];
      }
    }
    return true;
  };

  int ans = -1;
  vector<int> res;

  for (int mask = 0; mask < (1 << n); ++mask) {
    if (!isIncMask(mask)) continue;

    string t = "";
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) continue;
      t.push_back(s[i]);
    }

    if (isPalindrome(t)) {
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          res.push_back(i + 1);
        }
      }
      cout << (int)res.size() << '\n';
      for (int i = 0; i < (int)res.size(); ++i) {
        cout << res[i] << " \n"[i + 1 == (int)res.size()];
      }
      return;
    }
  }

  cout << -1 << '\n';
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