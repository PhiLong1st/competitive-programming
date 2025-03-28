public class Solution
{
    public int[] MaxPoints(int[][] grid, int[] queries)
    {
        int q = queries.Length;
        int n = grid.Length;
        int m = grid[0].Length;
 
        int[] ans = new int[q];
        var save = new List<(int val, int idx)>();
 
        for (int i = 0; i < q; ++i)
        {
            save.Add((queries[i], i));
        }
 
        save.Sort((a, b) => a.val.CompareTo(b.val));
 
        int[] dx = { 0, 0, 1, -1 };
        int[] dy = { 1, -1, 0, 0 };
        bool[,] visited = new bool[n, m];
 
        var que = new PriorityQueue<(int, int), int>();
        int cnt = 0;
 
        que.Enqueue((0, 0), grid[0][0]);
        visited[0, 0] = true;

        for (int i = 0; i < q; ++i)
        {
            while (que.Count > 0)
            {
                var (x, y) = que.Peek();
                int val = grid[x][y];

                if (val >= save[i].val) 
                {
                    break;
                }
                
                cnt++;
                que.Dequeue();

                for (int d = 0; d < 4; ++d)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
 
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx, ny])
                    {
                        que.Enqueue((nx, ny), grid[nx][ny]);
                        visited[nx, ny] = true;
                    }
                }
            }

            ans[save[i].idx] = cnt;
        }
 
        return ans;
    }
}