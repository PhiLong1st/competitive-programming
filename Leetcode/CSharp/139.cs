public class Solution
{
    public bool WordBreak(string s, IList<string> wordDist)
    {
        int n = s.Length;
        var wordSet = new HashSet<string>(wordDist);
        bool[] dp = new bool[n + 1];
        dp[0] = true;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && wordSet.Contains(s.Substring(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
}