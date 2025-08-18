/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:53:37
*/
public class Solution
{
    public string ShiftingLetters(string s, int[][] shifts)
    {
        int n = s.Length;
        char[] ans = new char[n];
        int[] sum = new int[n + 1];

        for (int i = 0; i < shifts.Length; ++i)
        {
            if (shifts[i][2] == 0)
            {
                sum[shifts[i][0]]--;
                sum[shifts[i][1] + 1]++;
            }
            else
            {
                sum[shifts[i][0]]++;
                sum[shifts[i][1] + 1]--;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            sum[i] += (i == 0) ? 0 : sum[i - 1];
        }

        for (int i = 0; i < n; ++i)
        {
            sum[i] %= 26;
            int newChar = ((s[i] - 'a') + sum[i] + 26) % 26 + 'a';
            ans[i] = (char)newChar;
        }

        return new string(ans);
    }
}