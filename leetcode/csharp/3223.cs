/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:50:00
*/
public class Solution
{
    public int MinimumLength(string s)
    {
        int ans = 0;
        int[] cnt = new int[26];

        for (int i = 0; i < s.Length; ++i)
        {
            cnt[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i] > 2)
            {
                ans += 2 - (cnt[i] % 2);
            }
            else
            {
                ans += cnt[i];
            }
        }

        return ans;
    }
}