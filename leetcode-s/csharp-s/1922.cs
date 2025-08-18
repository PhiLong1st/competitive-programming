/*
    Code by: KoKoDuDu
    Created: 2025.04.14 01:05:11
*/
public class Solution
{
    public int CountGoodNumbers(long n)
    {
        const int mod = (int)1e9 + 7;
        int count = 1 + (int)((n & 1) << 2);
        int mul = 20;

        for (n >>= 1; ; mul = (int)((long)mul * mul % mod))
        {
            if ((n & 1) > 0) count = (int)((long)count * mul % mod);
            if ((n >>= 1) == 0) return count;
        }
    }
}