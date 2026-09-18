/*
 Code by: Algorillas
 Created: 2026.09.17 20:12:14
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

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

struct Frac {
  int num, dem;
  Frac(int a, int b) { num = a, dem = b; };
  Frac(Frac a, Frac b) {
    num = a.num * b.dem;
    dem = a.dem * b.num;
    this->norm();
  };
  void norm() {
    int _g = gcd(num, dem);
    num /= _g;
    dem /= _g;
  }
  friend std::ostream& operator<<(std::ostream& os, const Frac& x) {
    return os << "(" << x.num << " / " << x.dem << ")";
  }
};

Frac Plus(Frac a, Frac b) {
  Frac res = Frac(a.num * b.dem + b.num * a.dem, b.dem * a.dem);
  res.norm();
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<char> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  dbg(s);
  stack<Frac> nums;
  stack<int> track;
  track.push(0);
  for (int i = 0; i < n; ++i) {
    if (isdigit(s[i])) {
      nums.push(Frac(s[i] - '0', 1));
      int x = track.top();
      if (x > 3) {
        dbg(i);
        return void(cout << "-1\n");
      }
      track.pop();
      track.push(x + 1);
    } else {
      if (s[i] == '(') {
        track.push(0);
      }

      if (s[i] == ')') {
        vector<Frac> seq;
        for (int j = 0; j < 3; ++j) {
          seq.push_back(nums.top());
          nums.pop();
        }
        reverse(all(seq));
        Frac x(seq[1], seq[2]);
        x = Plus(seq[0], x);
        nums.push(x);
        dbg(x);
        if (track.empty()) {
          dbg(i);
          return void(cout << "-1\n");
        }
        int cnt = track.top();
        if (cnt != 3) {
          dbg(i, cnt);
          return void(cout << "-1\n");
        }
        track.pop();
        if (track.size()) {
          int t = track.top();
          track.pop();
          track.push(t + 1);
        }
      }
    }
  }
  if (nums.size() != 1) return void(cout << "-1\n");
  auto res = nums.top();
  cout << res.num << ' ' << res.dem << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}