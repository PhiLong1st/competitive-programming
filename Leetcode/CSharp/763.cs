/*
    Code by: KoKoDuDu
    Created: 2025.03.30 10:58:05
*/
public class Solution
{
    public IList<int> PartitionLabels(string s)
    {
        var ans = new List<int>();
        int n = s.Length;

        int[] lastIndex = new int[26];
        for (int i = 0; i < n; ++i)
        {
            lastIndex[s[i] - 'a'] = i;
        }

        int start = 0, end = 0;
        for (int i = 0; i < n; ++i)
        {
            end = Math.Max(end, lastIndex[s[i] - 'a']);
            if (i == end)
            {
                ans.Add(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
}
