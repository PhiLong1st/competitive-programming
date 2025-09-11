/*
    Code by: KoKoDuDu
    Created: 2025.09.11 10:00:14
*/
public class Solution
{
  public string SortVowels(string s)
  {
    List<char> vowels = new();
    List<int> positions = new();
    StringBuilder sb = new(s);

    for (int i = 0; i < s.Length; ++i)
    {
      char c = s[i];
      if ("aeiouAEIOU".Contains(c))
      {
        vowels.Add(c);
        positions.Add(i);
      }
    }

    vowels.Sort();
    for (int i = 0; i < vowels.Count(); ++i)
    {
      sb[positions[i]] = vowels[i];
    }

    return sb.ToString();
  }
}