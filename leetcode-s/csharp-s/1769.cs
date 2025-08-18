/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:52:54
*/
public class Solution
{
    public int[] MinOperations(string boxes)
    {
        int n = boxes.Length;
        int[] ans = new int[n], sum = new int[n];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (boxes[j] == '1')
                {
                    ans[i] += Math.Abs(i - j);
                }
            }
        }

        return ans;
    }
}