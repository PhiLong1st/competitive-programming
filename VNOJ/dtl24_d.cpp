
/*
    Code by: KoKoDuDu
    Created: 02.11.2024 15:19:04
    Link: https://oj.vnoi.info/problem/dtl24_d
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
void solve() {
    string s;
    cin >> s;
    vector<int> charCount(26, 0);
    int same = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) {
            same = false;
            break;
        }
    }
    if (same) {
        cout << "Amidala\n";
        return;
    }
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        charCount[c - 'a']++;
    }
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (charCount[i] % 2 != 0) {
            oddCount++;
        }
    }
    cout << ((oddCount == 1) ? ("Amidala\n") : ("Skywalker\n"));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}