#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A';
  return a;
}
string to_lower(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A';
  return a;
}

template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T gcd(initializer_list<T> __l) {
  int a = 0;
  for (auto x : __l) {
    a = gcd(a, x);
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T cube(T x) {
  return x * x * x;
}

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int q;
  cin >> q;
  int nSum = 0, curSum = 0;
  int last = 0, rev = 0;
  deque<int> d;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      if (d.empty()) {
        cout << "0\n";
        continue;
      }
      if (rev % 2 == 0) {
        int c = d.back();
        curSum += nSum;
        curSum -= d.size() * c;
        d.pop_back();
        d.push_front(c);
      } else {
        int c = d.front();
        curSum += nSum;
        curSum -= d.size() * c;
        d.pop_front();
        d.push_back(c);
      }
    } else if (t == 2) {
      curSum = (d.size() + 1) * nSum - curSum;
      rev++;
    } else {
      int k;
      cin >> k;
      if (rev % 2 == 0) {
        d.push_back(k);
      } else {
        d.push_front(k);
      }
      nSum += k;
      curSum += k * d.size();
    }
    cout << curSum << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
