using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int MinimumIndex(IList<int> nums)
    {
        int candidate = 0;
        int count = 0;

        foreach (int num in nums)
        {
            if (count == 0)
            {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        int totalCount = nums.Count(x => x == candidate);
        int n = nums.Count;

        int prefixCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == candidate)
            {
                prefixCount++;
            }

            if (prefixCount * 2 > (i + 1) && (totalCount - prefixCount) * 2 > (n - i - 1))
            {
                return i;
            }
        }

        return -1;
    }
}
