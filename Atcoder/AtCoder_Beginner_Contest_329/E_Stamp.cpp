#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 0307;
bool used[maxN];
int N, M;
string S, T;

bool match(int pos)
{
    for (int i = pos; i < pos + M; ++i)
    {
        if (i < 0 || i >= N || S[i] != '?' && S[i] != T[i - pos])
        {
            return false;
        }
    }
    return true;
}

void dfs(int pos)
{
    used[pos] = true;
    fill(S.begin() + pos, S.begin() + pos + M, '?');
    for (int i = pos - M + 1; i <= pos + M; ++i)
    {
        if (match(i) && !used[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    cin >> N >> M;
    cin >> S;
    cin >> T;
    memset(used, false, sizeof(used));
    for (int i = 0; i < N; ++i)
    {
        if (match(i) && !used[i])
        {
            dfs(i);
        }
    }

    cout << (all_of(S.begin(), S.end(), [](char c)
        {
            return c == '?';
        }) ? "Yes" : "No") << endl;

    return 0;
}
