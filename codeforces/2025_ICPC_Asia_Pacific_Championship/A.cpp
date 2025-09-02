
#include <bits/stdc++.h>
#define int long long
using namespace std;

int nP4(int n)
{
    return n * (n - 1) * (n - 2) * (n - 3);
}

int nP2(int n)
{
    return n * (n - 1);
}

int nC2(int n)
{
    return n * (n - 1) / 2;
}

void solve()
{
    int r, c;
    cin >> r >> c;
    vector<vector<char>> a(r, vector<char>(c));
    vector<bitset<2000>> rowState(r), colState(c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            rowState[i][j] = (a[i][j] == '.');
            colState[j][i] = (a[i][j] == '.');
        }

    vector<int> row(r, 0), col(c, 0);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == '#')
                continue;
            row[i]++;
            col[j]++;
        }

    int res = 0;
    // one
    for (int i = 0; i < r; i++)
        res += nP4(row[i]);
    for (int i = 0; i < c; i++)
        res += nP4(col[i]);

    // two
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == '#')
                continue;
            res += nP2(row[i] - 1) * (col[j] - 1) * 2;
            res += nP2(col[j] - 1) * (row[i] - 1) * 2;
        }
    }

    // three
    for (int i = 0; i < r; i++)
    {
        for (int j = i + 1; j < r; j++)
        {
            int k = (rowState[i] & rowState[j]).count();
            res += k * (row[i] - 1) * (row[j] - 1) * 2;
        }
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = i + 1; j < c; j++)
        {
            int k = (colState[i] & colState[j]).count();
            res += k * (col[i] - 1) * (col[j] - 1) * 2;
        }
    }

    cout << res << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t-- > 0)
        solve();
}