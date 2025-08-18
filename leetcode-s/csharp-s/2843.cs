/*
    Code by: KoKoDuDu
    Created: 2025.04.11 11:10:43
*/
public class Solution
{
    public int CountSymmetricIntegers(int low, int high)
    {
        int res = 0;

        for (int i = low; i <= high; i++)
        {
            if (isSymmetric(i)) res++;
        }

        return res;
    }
    public bool isSymmetric(int num)
    {
        string s = num.ToString();
        int n = s.Length;

        if (n % 2 == 1)
        {
            return false;
        }

        int leftSum = 0;
        int rightSum = 0;

        for (int i = 0; i < n / 2; i++)
        {
            leftSum += s[i] - '0';
            rightSum += s[n - i - 1] - '0';
        }

        return leftSum == rightSum;
    }
}