#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

struct Res {
  bool isOk;
  string resA, resB, resC;
};

Res solve(int a, int b, int c) {
  string resA, resB, resC;

  if (a == 0 && b == 0 && c == 0) {
    return {1, "a", "a", "a"};
  }

  if (a + b < c) {
    return {0, "", "", ""};
  }

  if (a == 0 && b == 0) {
    return {0, "", "", ""};
  }

  if (a == 0) {
    if (b != c) {
      return {0, "", "", ""};
    }

    for (int i = 0; i < c; ++i) {
      resC += "c";
    }
    return {1, "a", "a", resC};
  }

  for (int i = 0; i < c - b; ++i) {
    resA += "c";
  }

  for (int i = 0; i < a - c + b; ++i) {
    resA += "a";
  }

  for (int i = 0; i < b - a; ++i) {
    resA += "b";
  }

  for (int i = 0; i < b; ++i) {
    resB += "b";
  }

  for (int i = 0; i < c; ++i) {
    resC += "c";
  }

  return {1, resA, resB, resC};
}

int check(const string& s, const string& t) {
  int n = sz(s), m = sz(t);
  vector<int> prev(m + 1), cur(m + 1);
  for (int j = 0; j <= m; ++j) prev[j] = j;
  for (int i = 1; i <= n; ++i) {
    cur[0] = i;
    for (int j = 1; j <= m; ++j) {
      int cost = (s[i - 1] != t[j - 1]);
      cur[j] = min({prev[j] + 1, cur[j - 1] + 1, prev[j - 1] + cost});
    }
    swap(prev, cur);
  }
  return prev[m];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  if (fopen("in.txt", "r")) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }

  int t = 1;
  while (t--) {
    int oa, ob, oc;
    cin >> oa >> ob >> oc;

    vector<int> val = {oa, ob, oc};
    sort(all(val));
    int a = val[0], b = val[1], c = val[2];

    auto [isOk, resA, resB, resC] = solve(a, b, c);
    if (!isOk) {
      cout << "No\n";
      continue;
    }

    cout << "Yes\n";

    vector<int> p = {0, 1, 2};
    vector<string> str(3);
    vector<string> arr = {resA, resB, resC};

    do {
      str[0] = arr[p[0]];
      str[1] = arr[p[1]];
      str[2] = arr[p[2]];

      int dAB = check(str[0], str[1]);
      int dAC = check(str[0], str[2]);
      int dBC = check(str[1], str[2]);

      if (dAB == oa && dAC == ob && dBC == oc) {
        cout << str[0] << '\n' << str[1] << '\n' << str[2] << '\n';
        return 0;
      }

    } while (next_permutation(p.begin(), p.end()));

    cout << "No\n";
  }
}