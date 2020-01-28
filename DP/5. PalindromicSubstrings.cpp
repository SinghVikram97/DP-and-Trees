// https://leetcode.com/problems/palindromic-substrings/

// Brute force
// O(n^3)
class Solution
{
public:
  bool isPalindrome(string &s, int i, int j)
  {

    while (i <= j)
    {
      if (s[i] != s[j])
      {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

  int countSubstrings(string s)
  {

    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        if (isPalindrome(s, i, j))
        {
          count++;
        }
      }
    }
    return count;
  }
};

// Optimised
// O(n^2)
class Solution
{
public:
  int countSubstrings(string s)
  {

    int n = s.length();
    int count = 0;

    // For every palindrome one of the word will be a middle word
    // So lets count no of palidromes with each word as middle word
    // Sum of them will be the answer

    // Correction
    // For cases like abcc
    // cc is a palindrome ie. even length
    // So consider case when it is right word too

    for (int i = 0; i < n; i++)
    {

      // select s[i] as middle word

      int left = i;
      int right = i;

      while (left >= 0 && right < n && s[left] == s[right])
      {
        count++;
        left--;
        right++;
      }

      // select s[i] as right word

      right = i;
      left = i - 1;

      while (left >= 0 && right < n && s[left] == s[right])
      {
        count++;
        left--;
        right++;
      }
    }
    return count;
  }
};