#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const ll maxN = 37;
const ll INF = 1e18;
pll dp[(1 << 20) + 1][20], best[(1 << 20)];
ll n, x;
ll w[maxN];
int main()
{
    cin >> n >> x;
    for (ll i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    //    for( ll i = 1 ; i < (1<<n); i ++ )
    //    {
    //        for( ll j = 0 ; j < n ; j ++ )
    //        {
    //            dp[i][j].first=1000;
    //            dp[i][j].second=0;
    //        }
    //    }
    for (ll i = 0; i < n; i++)
    {
        dp[(1 << i)][i].first = 1;
        dp[(1 << i)][i].second = x - w[i];
    }
    for (ll state = 1; state < (1 << n); state++)
    {
        best[state].first = INF;
        best[state].second = 0;
        for (ll i = 0; i < n; i++)
        {
            if ((state & (1 << i)) == 0) continue;
            if (best[state].first > dp[state][i].first)
            {
                best[state].first = dp[state][i].first;
                best[state].second = dp[state][i].second;
            }
            else if (best[state].first == dp[state][i].first)
            {
                best[state].second = max(best[state].second, dp[state][i].second);
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if ((state & (1 << i)) == 0)
            {
                //                pll data = make_pair(INF,0);
                //                for( ll j = 0 ; j < n ; j ++ )
                //                {
                ////                    dp[newState][i].first
                //                    if((state&(1<<j))==0) continue;
                //                    if(dp[state][j].second<w[i])
                //                    {
                ////                        data.first = min(dp[state][j].first + 1,data.first) ;
                //                        if(data.first>dp[state][j].first + 1)
                //                        {
                //                            data.first = dp[state][j].first + 1 ;
                //                            data.second = x-w[i];
                //                        }
                //                    }
                //                    else if(data.first>dp[state][j].first)
                //                    {
                //                        data.first = dp[state][j].first;
                //                        data.second = dp[state][j].second - w[i];
                //                    }
                //                    else if(data.first==dp[state][j].first)
                //                    {
                //                        data.second = max(data.second,dp[state][j].second-w[i]);
                //                    }
                //                }
                ll newState = (state | (1 << i));
                if (best[state].second < w[i])
                {
                    dp[newState][i].first = best[state].first + 1;
                    dp[newState][i].second = x - w[i];
                }
                else
                {

                    dp[newState][i].first = best[state].first;
                    dp[newState][i].second = best[state].second - w[i];
                }
            }
        }
    }
    // cout<<(1<<n);
    ll kq = INF;
    for (ll i = 0; i < n; i++)
    {
        kq = min(kq, dp[(1 << n) - 1][i].first);
    }
    cout << kq;
}
