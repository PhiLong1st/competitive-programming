/*
Code by: KoKoDuDu
Created: 2025.08.04 14:34:47
*/
public class Solution
{
  public int TotalFruit(int[] fruits)
  {
    int ans = 0;
    int n = fruits.Length;
    int cntDiff = 0;
    int l = 0, r = 0;
    var cntFruit = new int[n];

    while (r < n)
    {
      while (r < n && cntDiff <= 2)
      {
        if (cntFruit[fruits[r]] == 0)
        {
          cntDiff++;
        }

        if (cntDiff <= 2)
        {
          ans = Math.Max(ans, r - l + 1);
          Console.WriteLine(l + " " + r);
        }

        cntFruit[fruits[r]]++;

        r++;
      }

      while (l < r && cntDiff > 2)
      {
        cntFruit[fruits[l]]--;

        if (cntFruit[fruits[l]] == 0)
        {
          cntDiff--;
        }

        l++;
      }

    }

    return ans;
  }
}
