#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += s[i] == 'W';
    if (cnt % 2 != 0)
        return void(cout << "NO\n");

    int j = 0, half = cnt / 2;
    while (cnt > half)
    {
        if (s[j] == 'W')
        {
            --cnt;
        }
        ++j;
    }
    vector<int> vst(2 * n);
    int wCount = 0;
    for (int i = 0; i < n; ++i)
    {
        if (vst[i])
            continue;
        if (s[i] == 'W')
        {
            wCount++;
            while (j < n && s[j] != 'W' && !vst[j])
                ++j;
            if (j == n)
                return void(cout << "NO\n");
            vst[j] = 1;
            ++j;
        }
        else
        {
            if (wCount < half)
                return void(cout << "NO\n");
            while (j < 2 * n && s[j] != 'W' && !vst[j])
                ++j;
            if (j == 2 * n)
                return void(cout << "NO\n");
            vst[j] = 1;
            ++j;
        }
    }
    int cnt2 = 0;
    for (int i = n; i < 2 * n; ++i)
        cnt2 += s[i] == 'R';
    int cj = 0;
    cerr << "cnt2: " << cnt2 << endl;
    for (; j < 2 * n; ++j)
    {
        cj += s[j] == 'R';
    }
    if (cj < cnt2 / 2)
        return void(cout << "NO\n");
    cout << "YES\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}

// RRWWRWW || RRRRWWW

// 1 2 3
// 8 9 10