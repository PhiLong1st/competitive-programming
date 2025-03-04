/*
    Code by: KoKoDuDu
*/
#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 0307;
const int MOD = 1e9 + 7;
//vector<string>save;
int check[17][17], kq = 0;
string s;
bool validMove(int xx, int yy)
{
    return (xx >= 1 && xx <= 7 && yy >= 1 && yy <= 7 && check[xx][yy] == 0);
}
void solve(int x, int y, string tmp)
{
    bool kt = true;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (s[i] != '?' && tmp[i] != s[i])
        {
            kt = false;
            break;
        }
    }
    if (!kt)
    {
        return;
    }
    if (x == 7 && y == 1)
    {
        //save.push_back(tmp);
        if (tmp.size() == 48)
            kq++;
        return;
    }
    //cout<<x<<" "<<y<<"\n";
    if ((check[x][y - 1] == 1 && check[x][y + 1] == 1 && check[x + 1][y] == 0 && check[x - 1][y] == 0) || (check[x][y - 1] == 0 && check[x][y + 1] == 0 && check[x + 1][y] == 1 && check[x - 1][y] == 1))
    {
        return;
    }
    int type = 0;
    //1 1 111
    //111 1 1
    if ((check[x][y + 2] == 1 && check[x][y + 1] == 0 && check[x + 1][y + 1] == 1 && check[x + 1][y] == 1 && check[x + 1][y + 2] == 1) || (check[x][y + 2] == 1 && check[x][y + 1] == 0 && check[x - 1][y + 1] == 1 && check[x - 1][y] == 1 && check[x - 1][y + 2] == 1))
    {
        type = 1;//right
    }
    if (y >= 2)
    {
        //1 1  111
        //111  1 1
        if ((check[x][y - 2] == 1 && check[x][y - 1] == 0 && check[x + 1][y - 1] == 1 && check[x + 1][y] == 1 && check[x + 1][y - 2] == 1) || (check[x][y - 2] == 1 && check[x][y - 1] == 0 && check[x - 1][y - 1] == 1 && check[x - 1][y] == 1 && check[x - 1][y - 2] == 1))
        {
            type = 2;//left
        }
    }
    if (x >= 2)
    {
        //11   11
        //1     1
        //11   11
        if ((check[x][y - 1] == 1 && check[x - 1][y] == 0 && check[x - 1][y - 1] == 1 && check[x - 2][y] == 1 && check[x - 2][y - 1] == 1) || (check[x][y + 1] == 1 && check[x - 1][y] == 0 && check[x - 1][y + 1] == 1 && check[x - 2][y] == 1 && check[x - 2][y + 1] == 1))
        {
            type = 3;//up
        }
    }
    //11   11
    //1     1
    //11   11
    if ((check[x][y - 1] == 1 && check[x + 1][y] == 0 && check[x + 1][y - 1] == 1 && check[x + 2][y] == 1 && check[x + 2][y - 1] == 1) || (check[x][y + 1] == 1 && check[x + 1][y] == 0 && check[x + 1][y + 1] == 1 && check[x + 2][y] == 1 && check[x + 2][y + 1] == 1))
    {
        type = 4;//down
    }
    check[x][y] = 1;
    if (type == 0)
    {
        if (validMove(x, y + 1))//right
        {
            string res = tmp + "R";
            solve(x, y + 1, res);
            //tmp.pop_back();
        }
        if (validMove(x, y - 1))//left
        {
            string res = tmp + "L";
            solve(x, y - 1, res);
            //tmp.pop_back();
        }
        if (validMove(x - 1, y))//up
        {
            string res = tmp + "U";
            solve(x - 1, y, res);
            //tmp.pop_back();
        }
        if (validMove(x + 1, y))//down
        {
            string res = tmp + "D";
            solve(x + 1, y, res);
            // tmp.pop_back();
        }
    }
    else
    {
        if (type == 1)
        {
            if (validMove(x, y + 1))//right
            {
                string res = tmp + "R";
                solve(x, y + 1, res);
                //tmp.pop_back();
            }
        }
        if (type == 2)
        {
            if (validMove(x, y - 1))//left
            {
                string res = tmp + "L";
                solve(x, y - 1, res);
                //tmp.pop_back();
            }
        }
        if (type == 3)
        {
            if (validMove(x - 1, y))//up
            {
                string res = tmp + "U";
                solve(x - 1, y, res);
                //tmp.pop_back();
            }
        }
        if (type == 4)
        {
            if (validMove(x + 1, y))//down
            {
                string res = tmp + "D";
                solve(x + 1, y, res);
                // tmp.pop_back();
            }
        }
    }
    check[x][y] = 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    string tmp = "";
    cin >> s;
    check[0][0] = 1;
    for (int i = 1; i <= 7; i++)
    {
        check[0][i] = 1;
        check[i][0] = 1;
        check[8][i] = 1;
        check[i][8] = 1;
    }
    solve(1, 1, tmp);
    cout << kq;
    //cout<<save.size();
    //cout<<validMove(1,2);
}
