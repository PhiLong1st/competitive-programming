
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a)
{
   for (int i = 0; i < (int)a.size(); ++i)
      if (a[i] >= 'a' && a[i] <= 'z')
         a[i] -= 'a' - 'A';
   return a;
}
string to_lower(string a)
{
   for (int i = 0; i < (int)a.size(); ++i)
      if (a[i] >= 'A' && a[i] <= 'Z')
         a[i] += 'a' - 'A';
   return a;
}

template <class T>
T gcd(T a, T b)
{
   T r;
   while (b != 0)
   {
      r = a % b;
      a = b;
      b = r;
   }
   return a;
}
template <class T>
T gcd(initializer_list<T> __l)
{
   int a = 0;
   for (auto x : __l)
   {
      a = gcd(a, x);
   }
   return a;
}
template <class T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T>
T sqr(T x) { return x * x; }
template <class T>
T cube(T x) { return x * x * x; }

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

vector<int> f[N];

void sieve()
{
   for (int i = 1; i * i < N; ++i)
   {
      for (int j = i * i; j < N; j += i)
      {
         f[j].push_back(i);
         if (i != j / i)
            f[j].push_back(j / i);
      }
   }
}

void solve()
{
   int n, q;
   cin >> n >> q;
   vector<int> a(n);
   unordered_map<int, vector<int>> index;
   for (int i = 0; i < n; ++i)
   {
      cin >> a[i];
      index[a[i]].push_back(i);
   }
   while (q--)
   {
      int k, l, r;
      cin >> k >> l >> r;
      --l;
      --r;
      vector<pair<int, int>> ft;
      for (auto& c : f[k])
      {
         if (index.count(c))
         {
            int i = lower_bound(all(index[c]), l) - index[c].begin();
            if (i < sz(index[c]) && index[c][i] <= r)
            {
               ft.emplace_back(c, index[c][i]);
            }
         }
      }
      sort(all(ft), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
      int ans = 0;
      int pre = l;
      for (auto [c, id] : ft)
      {
         if (pre < id)
         {
            ans += (id - pre) * k;
         }
         pre = id + 1;
         while (k % c == 0)
         {
            k /= c;
         }
         ans += k;
      }
      if (pre <= r)
      {
         ans += (r - pre + 1) * k;
      }
      cout << ans << '\n';
   }
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   sieve();
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}
