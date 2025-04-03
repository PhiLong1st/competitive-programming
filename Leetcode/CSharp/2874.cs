/*
    Code by: KoKoDuDu
    Created: 2025.04.03 09:44:53
*/
public class Solution
{
    public long MaximumTripletValue(int[] nums)
    {
        long ans = 0;
        int n = nums.Length;
        var arr = new long[n];
        long maxx = nums[0];

        for (int i = 1; i < n; ++i)
        {
            arr[i] = Math.Max(arr[i - 1], maxx - nums[i]);
            maxx = Math.Max(maxx, nums[i]);
        }

        for (int i = 2; i < n; ++i)
        {
            ans = Math.Max(ans, nums[i] * arr[i - 1]);
        }

        return ans;
    }
}