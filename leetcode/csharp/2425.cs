/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:51:44
*/
public class Solution
{
    public int XorAllNums(int[] nums1, int[] nums2)
    {
        int n = nums1.Length;
        int m = nums2.Length;
        int s1 = 0, s2 = 0;

        foreach (int x in nums1)
        {
            s1 ^= x;
        }

        foreach (int x in nums2)
        {
            s2 ^= x;
        }

        if (n % 2 == 0)
        {
            if (m % 2 == 0)
            {
                return 0;
            }
            else
            {
                return s1;
            }
        }
        else
        {
            if (m % 2 == 0)
            {
                return s2;
            }
            else
            {
                return s1 ^ s2;
            }
        }
    }
}