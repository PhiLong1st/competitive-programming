/*
    Code by: KoKoDuDu
*/
#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 0307;
const int MOD = 1e9 + 7;
char s[100][100];
int check_col[100], kq = 0, check_first[100], check_second[100];
void solve(int row)
{
    for (int i = 1; i <= 8; i++)
    {
        if (s[row][i] == '.' && check_col[i] == 0 && check_first[8 + i - row] == 0 && check_second[2 * 8 - row - i + 1] == 0)
        {
            check_col[i] = 1;
            check_first[8 + i - row] = 1;
            check_second[2 * 8 - row - i + 1] = 1;
            if (row < 8)
            {
                solve(row + 1);
            }
            else
            {
                kq++;
            }
            check_col[i] = 0;
            check_first[i + 8 - row] = 0;
            check_second[2 * 8 - row - i + 1] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            cin >> s[i][j];
        }
    }
    solve(1);
    cout << kq;
}
