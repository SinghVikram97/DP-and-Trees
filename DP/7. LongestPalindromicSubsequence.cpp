// https://leetcode.com/problems/longest-palindromic-subsequence/

// Brute force
// Recursion - try all subsequences

class Solution
{
public:
  bool isPalindrome(string s)
  {

    int start = 0;
    int end = s.length() - 1;

    while (start <= end)
    {
      if (s[start] != s[end])
      {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }

  void func(string s, int i, string temp, int &max_length)
  {

    int n = s.length();

    if (i == n)
    {
      if (isPalindrome(temp))
      {
        int tl = temp.length();
        max_length = max(max_length, tl);
      }
      return;
    }

    // Can take or don't take
    func(s, i + 1, temp, max_length);

    func(s, i + 1, temp + s[i], max_length);

    return;
  }

  int longestPalindromeSubseq(string s)
  {

    int n = s.length();

    int max_length = -1;

    string temp = "";

    func(s, 0, temp, max_length);

    return max_length;
  }
};