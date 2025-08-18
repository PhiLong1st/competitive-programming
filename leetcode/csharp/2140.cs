/*
    Code by: KoKoDuDu
    Created: 2025.04.01 10:42:49
*/
public class Solution
{
    public long MostPoints(int[][] questions)
    {
        int n = questions.Length;
        long[] dp = new long[n + 1];

        for (int i = n - 1; i >= 0; i--)
        {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            long skip = dp[i + 1];
            long solve = points;
            if (i + brainpower + 1 < n)
            {
                solve += dp[i + brainpower + 1];
            }
            dp[i] = Math.Max(skip, solve);
        }

        return dp[0];
    }
}