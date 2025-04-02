/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:53:16
*/
public class Solution
{
    bool IsVowel(char s)
    {
        string vowel = "aeiou";
        return vowel.Contains(s);
    }
    public int[] VowelStrings(string[] words, int[][] queries)
    {
        int n = queries.Length;
        int m = words.Length;
        int[] ans = new int[n];
        int[] sum = new int[m];

        for (int i = 0; i < m; ++i)
        {
            if (IsVowel(words[i][0]) && IsVowel(words[i][words[i].Length - 1]))
            {
                sum[i] = 1;
            }
            sum[i] += (i == 0) ? 0 : sum[i - 1];
        }

        for (int i = 0; i < n; ++i)
        {
            ans[i] = sum[queries[i][1]] - ((queries[i][0] == 0) ? 0 : sum[queries[i][0] - 1]);
        }

        return ans;
    }
}