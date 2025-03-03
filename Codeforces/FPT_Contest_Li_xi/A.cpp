#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int mOD = 1e9 + 7;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int trapRainWater(vector<vector<int>>& h) {
    int vol = 0;
    const int m = h.size(), n = h[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));
    vector<vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    auto comp = [&](const array<int, 3>& a, const array<int, 3>& b) { return a[0] >= b[0]; };
    priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> min_heap(comp);

    for (int i = 0; i < n; i++) {
        min_heap.push({ h[0][i], 0, i });
        min_heap.push({ h[m - 1][i], m - 1, i });
        visited[0][i] = true;
        visited[m - 1][i] = true;
    }

    for (int i = 0; i < m; i++) {
        min_heap.push({ h[i][0], i, 0 });
        min_heap.push({ h[i][n - 1], i, n - 1 });
        visited[i][0] = true;
        visited[i][n - 1] = true;
    }

    while (!min_heap.empty()) {
        auto [height, row, col] = min_heap.top();
        min_heap.pop();
        for (auto dir : directions) {
            int r = row + dir[0], c = col + dir[1];
            if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {
                visited[r][c] = true;
                if (h[r][c] < height) {
                    vol += height - h[r][c];
                }
                min_heap.push({ max(height, h[r][c]), r, c });
            }
        }
    }
    return vol;
}


void solve() {
    int n, m;
    cin >> m >> n;
    vector<vector<int>> h(m, vector<int>(n));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> h[i - 1][j - 1];
        }
    }

    cout << trapRainWater(h);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
