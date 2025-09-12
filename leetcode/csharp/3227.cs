/*
    Code by: KoKoDuDu
    Created: 2025.09.12 13:24:36
*/
using System;

public class Solution
{
  public bool DoesAliceWin(string s)
  {
    foreach (char c in s)
    {
      if ("aeiou".Contains(c))
      {
        return true;
      }
    }
    return false;
  }
}