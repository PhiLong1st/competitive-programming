public class Solution
{
    public int MaximumScore(IList<int> nums, int k)
    {
        long ans = 1;
        int n = nums.Count;
        int[] arr = new int[n];
        int[] l = new int[n];
        int[] r = new int[n];
        var save = new List<(int num, long freq)>();
        long MOD = (long)1e9 + 7;

        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            int cnt = 0;
            for (int j = 2; j * j <= num; ++j)
            {
                if (num % j == 0)
                {
                    cnt++;
                    while (num % j == 0) num /= j;
                }
            }
            if (num > 1) cnt++;
            arr[i] = cnt;
        }

        var st = new Stack<int>();

        for (int i = 0; i < n; ++i)
        {
            while (st.Count > 0 && arr[st.Peek()] < arr[i]) st.Pop();
            l[i] = st.Count == 0 ? 0 : st.Peek() + 1;
            st.Push(i);
        }

        st.Clear();

        for (int i = n - 1; i >= 0; --i)
        {
            while (st.Count > 0 && arr[st.Peek()] <= arr[i]) st.Pop();
            r[i] = st.Count == 0 ? n - 1 : st.Peek() - 1;
            st.Push(i);
        }

        for (int i = 0; i < n; ++i)
        {
            long freq = (long)(i - l[i] + 1) * (r[i] - i + 1);
            save.Add((nums[i], freq));
        }

        save.Sort((a, b) => b.num.CompareTo(a.num));

        long remaining = k;

        foreach (var (num, freq) in save)
        {
            long used = Math.Min(freq, remaining);
            remaining -= used;
            ans = ans * ModPow(num, used, MOD) % MOD;
            if (remaining == 0) break;
        }

        return (int)ans;
    }

    private long ModPow(long a, long b, long mod)
    {
        long result = 1;
        while (b > 0)
        {
            if ((b & 1) == 1)
                result = result * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return result;
    }
}
