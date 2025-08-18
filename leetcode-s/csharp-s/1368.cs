/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:52:12
*/
public class Solution
{
    public int MinCost(int[][] grid)
    {
        int m = grid.Length, n = grid[0].Length;
        int ans = int.MaxValue;
        int[][] directions = new int[][]
        {
            new int[] {0, 1}, // Right
            new int[] {0, -1}, // Left
            new int[] {1, 0}, // Down
            new int[] {-1, 0} // Up
        };
        int[,] dp = new int[m, n];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i, j] = int.MaxValue;
            }
        }

        var queue = new Queue<Tuple<Tuple<int, int>, int>>();
        queue.Enqueue(Tuple.Create(Tuple.Create(0, 0), 0));

        dp[0, 0] = 0;

        while (queue.Count > 0)
        {
            var front = queue.Dequeue();
            var curr = front.Item1;
            int cost = front.Item2;
            int x = curr.Item1, y = curr.Item2;

            if (dp[x, y] < cost)
            {
                continue;
            }

            if (x == m - 1 && y == n - 1)
            {
                ans = Math.Min(ans, dp[x, y]);
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                {
                    continue;
                }

                int newCost = cost + (grid[x][y] != i + 1 ? 1 : 0);

                if (dp[nx, ny] > newCost)
                {
                    dp[nx, ny] = newCost;
                    queue.Enqueue(Tuple.Create(Tuple.Create(nx, ny), newCost));
                }
            }
        }

        return ans;
    }
}