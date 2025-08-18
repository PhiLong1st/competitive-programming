public class Solution
{
    public IList<int> MajorityElement(int[] nums)
    {
        var ans = new List<int>();
        int majorA = 0, majorB = 1;
        int cntA = 0, cntB = 0;
        int n = nums.Length;

        foreach (var i in nums)
        {
            if (i == majorA)
            {
                cntA++;
            }
            else if (i == majorB)
            {
                cntB++;
            }
            else if (cntA == 0)
            {
                majorA = i;
                cntA = 1;
            }
            else if (cntB == 0)
            {
                majorB = i;
                cntB = 1;
            }
            else
            {
                cntA--;
                cntB--;
            }
        }

        cntA = 0;
        cntB = 0;
        foreach (var i in nums)
        {
            if (i == majorA) cntA++;
            else if (i == majorB) cntB++;
        }

        if (cntA > n / 3) ans.Add(majorA);
        if (cntB > n / 3) ans.Add(majorB);

        return ans;
    }
}
