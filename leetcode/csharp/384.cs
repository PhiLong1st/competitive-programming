public class Solution
{
  private readonly int[] originalNums;

  public Solution(int[] nums)
  {
    originalNums = nums;
  }

  public int[] Reset() => (int[])originalNums.Clone();

  public int[] Shuffle()
  {
    int[] shuffledNums = (int[])originalNums.Clone();
    int numsLength = shuffledNums.Length;

    for (int times = 1; times <= 100; ++times)
    {
      Random rand = new Random();
      int firstIdx = rand.Next(numsLength);
      int secondIdx = rand.Next(numsLength);
      SwapElement(ref shuffledNums[firstIdx], ref shuffledNums[secondIdx]);
    }

    return shuffledNums;
  }

  private void SwapElement(ref int firstElement, ref int secondElement)
  {
    int tempElement = firstElement;
    firstElement = secondElement;
    secondElement = tempElement;
  }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.Reset();
 * int[] param_2 = obj.Shuffle();
 */