/*
 Code by: Algorillas
 Created: 2026.09.17 22:25:45
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

// function BlackBox( Banana ):
//  if len( Banana ) <= 4 :
//  exit("Too small Banana")
//  Apple = [] # [] is an empty list
//  Mango = 0
//  Papaya = len( Banana )
//  while( Papaya >= 2 ) :
//  Kiwi = Banana[ Mango ]
//  Apple.append( Kiwi )
//  Banana.pop( Mango )
//  Papaya = Papaya - 1
//  Mango = ( Kiwi + Mango - 1 ) % Papaya
//  # end of while
//  Apple.append( Banana[ 0 ] )
//  Pear = len( Apple ) - 1
//  Orange = Apple[ Pear ]
//  Lime = Apple[ 0 ]
//  Coconut = Orange % Pear
//  Melon = Apple[ Coconut ]
//  Apple[ 0 ] = Melon
//  Apple[ Coconut ] = Lime
//  return ( Apple )

vector<int> BlackBox(vector<int> arr) {
  if (arr.size() <= 4) {
    exit(0);
  }
  vector<int> new_arr;
  int index = 0;
  while (arr.size() >= 2) {
    int item = arr[index];
    new_arr.push_back(item);
    arr.erase(arr.begin() + index);
    index = (item + index - 1) % (int)(arr.size());
  }
  // 0 -> 9 -> arr[9]
  // 88 x
  // x 88
  new_arr.push_back(arr[0]);
  // int new_end = new_arr.size() - 1;
  // int new_item = new_arr[new_end];
  // int new_start = new_arr[0];
  // int new_index = new_item % new_end;
  // int next_item = new_arr[new_index];
  // new_arr[0] = next_item;
  // new_arr[new_index] = new_start;
  return new_arr;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& c : a) cin >> c;

  cout << BlackBox(a);
  return;

  int coconut = a[n - 1] % (n - 1);
  int first = a[coconut];
  swap(a[0], a[coconut]);

  vector<int> res(n);
  res[0] = a[0];

  vector<int> removed(n);
  removed[0] = 1;
  int index = 0;
  for (int i = 1; i < n; ++i) {
    int item = a[index];
    int extra = 0;
    a.erase(find(all(a), item));
    int prev = index;
    index = (item + index - 1) % (int)(a.size());
    for (int j = prev; j <= index + extra; ++j) extra += removed[j];
    res[index + extra] = item;
    removed[index + extra] = 1;
  }
  cout << res;

  // cout << a;
}

void solve1() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& c : a) cin >> c;

  int coconut = a[n - 1] % (n - 1);
  int first = a[coconut];
  swap(a[0], a[coconut]);

  cout << a << "\n";
  vector<int> res(n), removed;
  int index = 0;
  for (int i = 0; i < 3; i++) {
    int extra = 0;
    for (int rm : removed) extra += (rm < index);
    res[index + extra] = a[i];
    removed.push_back(index);
    dbg(i, index, extra, index + extra);
    index = (a[i] + index - 1) % (n - (i + 1));
  }
  for (int v : res) cout << v << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  solve1();
  return 0;
}

// next_id = (68 + 3 - 1) % 10 = 7

// (49 + 9 - 1) % 11 = 2
// (68 + 2 - 1) % 10 = 9
// index = (91 + 9 - 1) % 9;
