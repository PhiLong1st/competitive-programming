/*
 Code by: KoKoDuDu
 Created: 2025.11.21 12:42:25
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

void solve(int n) {
  vector<bool> used(n + 1);
  vector<int> ans;
  queue<int> evens, mul_odd_3, save;

  for (int i = 2; i <= n; i += 2) evens.push(i), used[i] = 1;
  for (int i = 3; i <= n; i += 6) mul_odd_3.push(i), used[i] = 1;

  for (int i = 1; i <= n; ++i) {
    if (used[i]) continue;
    save.push(i);
  }

  while (!evens.empty()) {
    int num = save.front();
    save.pop();
    ans.push_back(num);

    int x = evens.front();
    evens.pop();
    ans.push_back(x);

    if (!evens.empty()) {
      int y = evens.front();
      evens.pop();
      ans.push_back(y);
    }
  }

  while (!mul_odd_3.empty() && !save.empty()) {
    int num = save.front();
    save.pop();
    ans.push_back(num);

    int x = mul_odd_3.front();
    mul_odd_3.pop();
    ans.push_back(x);

    if (!mul_odd_3.empty()) {
      int y = mul_odd_3.front();
      mul_odd_3.pop();
      ans.push_back(y);
    }
  }

  while (!mul_odd_3.empty()) {
    int x = mul_odd_3.front();
    mul_odd_3.pop();
    ans.push_back(x);
  }

  while (!save.empty()) {
    int x = save.front();
    save.pop();
    ans.push_back(x);
  }

  for (auto& x : ans) cout << x << ' ';
  cout << '\n';

  // int res = 0;
  // for (int i = 2; i < ans.size(); ++i) {
  //   int g1 = gcd(ans[i], ans[i - 1]);
  //   int g2 = gcd(ans[i], ans[i - 2]);
  //   int g3 = gcd(ans[i - 1], ans[i - 2]);
  //   res += g1 == 1 && g2 == 1 && g3 == 1;
  // }

  // if (ans.size() != n) cerr << n << "Wrong size\n";
  // if (res > 6) cerr << n << "WA\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }

  return 0;
}
