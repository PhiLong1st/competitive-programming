/*
    Code by: KoKoDuDu
    Created: 2025.04.08 07:11:58
*/
public class Solution
{
    public int MinimumOperations(int[] nums)
    {
        int ans = 0;
        Dictionary<int, int> cnt = new Dictionary<int, int>();

        for (int i = nums.Length - 1; i >= 0; --i)
        {
            if (!cnt.ContainsKey(nums[i]))
            {
                cnt[nums[i]] = 0;
            }

            cnt[nums[i]] += 1;

            if (cnt[nums[i]] > 1)
            {
                break;
            }
            else
            {
                ans = i;
            }
        }

        return (ans + 2) / 3;
    }
}
