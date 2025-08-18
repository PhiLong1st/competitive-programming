/*
    Code by: KoKoDuDu
    Created: 2025.04.02 17:51:14
*/
public class Solution
{
    private int CountSetBits(int num)
    {
        int count = 0;
        while (num != 0)
        {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    private int AddSetBits(int num, int bitsToAdd)
    {
        int bitPos = 0;
        while (bitsToAdd > 0)
        {
            while (((num >> bitPos) & 1) == 1) bitPos++;
            num |= 1 << bitPos;
            bitsToAdd--;
        }
        return num;
    }

    private int RemoveSetBits(int num, int bitsToRemove)
    {
        while (bitsToRemove > 0)
        {
            num &= (num - 1);
            bitsToRemove--;
        }
        return num;
    }

    public int MinimizeXor(int num1, int num2)
    {
        int setBitsNum1 = CountSetBits(num1);
        int setBitsNum2 = CountSetBits(num2);

        if (setBitsNum1 == setBitsNum2) return num1;
        if (setBitsNum1 < setBitsNum2) return AddSetBits(num1, setBitsNum2 - setBitsNum1);
        return RemoveSetBits(num1, setBitsNum1 - setBitsNum2);
    }
}