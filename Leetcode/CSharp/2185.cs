/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:55:11
*/
public class Solution
{
    public int PrefixCount(string[] words, string pref)
    {
        int ans = 0;

        foreach (string s in words)
        {
            if (s.StartsWith(pref))
            {
                ans++;
            }
        }

        return ans;
    }
}