/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:50:38
*/
public class Solution
{
    public int[] FindThePrefixCommonArray(int[] A, int[] B)
    {
        int n = A.Length;
        int[] ans = new int[n];
        int[] cnt = new int[n + 1];

        for (int i = 0; i < n; ++i)
        {
            ans[i] = (i == 0 ? 0 : ans[i - 1]);

            if (A[i] == B[i])
            {
                ans[i]++;
                continue;
            }

            if (cnt[B[i]] != 0)
            {
                ans[i]++;
            }

            if (cnt[A[i]] != 0)
            {
                ans[i]++;
            }

            cnt[A[i]]++;
            cnt[B[i]]++;
        }

        return ans;
    }
}