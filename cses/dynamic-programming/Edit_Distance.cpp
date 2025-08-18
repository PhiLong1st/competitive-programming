#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10000];
int dp[5010][5010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    string s, t;
    cin >> s >> t;
    int pl = s.size();
    int pm = t.size();
    for (int i = 0; i <= pl; i++)
    {
        for (int j = 0; j <= pm; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[s.size()][t.size()];
}
