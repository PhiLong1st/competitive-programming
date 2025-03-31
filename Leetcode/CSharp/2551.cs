/*
    Code by: KoKoDuDu
    Created: 2025.03.31 20:16:15
*/
public class Solution
{
    public long PutMarbles(int[] w, int k)
    {
        int n = w.Length;
        long ans = 0;
        var save = new List<int>();

        for (int i = 1; i < n; ++i)
        {
            save.Add(w[i] + w[i - 1]);
        }

        save.Sort();

        for (int i = 0; i < k - 1; ++i)
        {
            ans -= save[i];
        }

        for (int i = save.Count - k + 1; i < save.Count; ++i)
        {
            ans += save[i];
        }

        return ans;
    }
}