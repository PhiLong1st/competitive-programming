#include<bits/stdc++.h>
using namespace std;
int a[37];
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < s.size() - 1; i++)
    {
        int dem = 0;
        while (s[i] == s[i + 1])
        {
            dem++;
            i++;
        }
        a[s[i] - 'a'] = max(a[s[i] - 'a'], dem + 1);
        //cout<<s[i]<<" "<<dem+1<<"\n";
    }
    int kq = 0;
    for (int i = 0; i < 30; i++)
    {
        kq += a[i];
    }
    cout << kq;
}
