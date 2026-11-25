/*
 Code by: KoKoDuDu
 Created: 2025.11.29 18:55:05
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
const int kMaxN = 307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }
int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

void add_mod(int& a, int b) { a = a + b >= kMod ? a + b - kMod : a + b; }
void minus_mod(int& a, int b) { a = (a - b + kMod) % kMod; }
void mul_mod(int& a, int b) { a = a * b % kMod; }

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

char dp[2][2][kMaxN][kMaxN][kMaxN];

struct Card {
  char op;
  int val;
  int type;

  Card() {}
  Card(char c, int x) : op(c), val(x) {
    if (op == '*') {
      type = (val % 2 == 0 ? 0 : 2);
    } else {
      type = (val % 2 ? 1 : 2);
    }
  }

  bool operator<(const Card& other) const {
    if (op != other.op) return op < other.op;
    return val < other.val;
  }
};

int me = 1;
int you = 0;
int first_player;

void solve() {
  int n;
  cin >> n;

  int moves = n;

  queue<Card> mul_0, add_1, other;
  map<Card, int> used;

  for (int i = 0; i < n; ++i) {
    char c;
    int val;
    cin >> c >> val;

    Card card(c, val);
    if (card.type == 0) {
      mul_0.push(card);
    } else if (card.type == 1) {
      add_1.push(card);
    } else {
      other.push(card);
    }
  }

  int initial_val;
  cin >> initial_val;
  initial_val &= 1;

  int a = (int)mul_0.size();
  int b = (int)add_1.size();
  int c = (int)other.size();

  auto calc = [&](auto&& calc, int cur, int w, int x, int y, int z) -> int {
    auto& res = dp[cur][w][x][y][z];
    if (res != -1) return res;

    if (x == 0 && y == 0 && z == 0) {
      int winner = w ? first_player : !first_player;
      return res = (winner == me);
    }

    int next = !cur;
    bool is_win;

    if (cur == me) {
      is_win = false;
      if (x > 0) is_win |= calc(calc, next, 0, x - 1, y, z);
      if (y > 0) is_win |= calc(calc, next, w ^ 1, x, y - 1, z);
      if (z > 0) is_win |= calc(calc, next, w, x, y, z - 1);
    } else {
      is_win = true;
      if (x > 0) is_win &= calc(calc, next, 0, x - 1, y, z);
      if (y > 0) is_win &= calc(calc, next, w ^ 1, x, y - 1, z);
      if (z > 0) is_win &= calc(calc, next, w, x, y, z - 1);
    }

    return res = is_win;
  };

  first_player = me;
  memset(dp, -1, sizeof(dp));

  int start;
  if (calc(calc, first_player, initial_val, a, b, c))
    start = me;
  else
    start = you;

  cout << (start == me ? "me\n" : "you\n");
  cout.flush();

  first_player = start;
  memset(dp, -1, sizeof(dp));

  auto apply_card = [&](Card& card, int& w, int& x, int& y, int& z) -> void {
    --moves;
    if (card.type == 0) {
      w = 0;
      --x;
    } else if (card.type == 1) {
      w = !w;
      --y;
    } else {
      --z;
    }
  };

  auto your_turn = [&](int& w, int& x, int& y, int& z) -> void {
    if (moves == 0) return;

    char c;
    int val;
    cin >> c >> val;
    Card card(c, val);

    used[card]++;
    apply_card(card, w, x, y, z);
  };

  auto f = [&](auto&& f, int cur, int w, int x, int y, int z) -> void {
    if (moves == 0) return;

    while (!mul_0.empty()) {
      Card card = mul_0.front();
      if (used[card] == 0) break;
      used[card]--;
      mul_0.pop();
    }

    while (!add_1.empty()) {
      Card card = add_1.front();
      if (used[card] == 0) break;
      used[card]--;
      add_1.pop();
    }

    while (!other.empty()) {
      Card card = other.front();
      if (used[card] == 0) break;
      used[card]--;
      other.pop();
    }

    int next = !cur;
    if (cur == me) {
      if (x > 0 && calc(calc, next, 0, x - 1, y, z)) {
        Card card = mul_0.front();
        mul_0.pop();

        cout << card.op << ' ' << card.val << '\n';
        cout.flush();

        apply_card(card, w, x, y, z);
        f(f, next, w, x, y, z);
        return;
      }

      if (y > 0 && calc(calc, next, !w, x, y - 1, z)) {
        Card card = add_1.front();
        add_1.pop();

        cout << card.op << ' ' << card.val << '\n';
        cout.flush();

        apply_card(card, w, x, y, z);
        f(f, next, w, x, y, z);
        return;
      }

      if (z > 0 && calc(calc, next, w, x, y, z - 1)) {
        Card card = other.front();
        other.pop();

        cout << card.op << ' ' << card.val << '\n';
        cout.flush();

        apply_card(card, w, x, y, z);
        f(f, next, w, x, y, z);
        return;
      }
    } else {
      your_turn(w, x, y, z);
      f(f, next, w, x, y, z);
    }
  };

  f(f, start, initial_val, a, b, c);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
