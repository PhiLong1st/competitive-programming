/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:54:05
*/
public class Solution
{
    public IList<string> StringMatching(string[] words)
    {
        List<string> ans = new List<string>();

        for (int i = 0; i < words.Length; ++i)
        {
            for (int j = 0; j < words.Length; ++j)
            {
                if (i == j) continue;
                if (words[j].Contains(words[i]))
                {
                    ans.Add(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
}