// https://leetcode.com/problems/longest-palindromic-substring/

// Based on previous approach
// O(n2)

class Solution
{
public:
  string longestPalindrome(string s)
  {

    int n = s.length();
    int max_length = -1;
    int st = 0, en = 0;

    for (int i = 0; i < n; i++)
    {

      int left = i;
      int right = i;

      while (left >= 0 && right < n && s[left] == s[right])
      {
        int temp_length = right - left + 1;
        if (temp_length > max_length)
        {
          st = left;
          en = right;
          max_length = temp_length;
        }
        left--;
        right++;
      }

      left = i - 1;
      right = i;

      while (left >= 0 && right < n && s[left] == s[right])
      {
        int temp_length = right - left + 1;
        if (temp_length > max_length)
        {
          st = left;
          en = right;
          max_length = temp_length;
        }
        left--;
        right++;
      }
    }
    return s.substr(st, en - st + 1);
  }
};
