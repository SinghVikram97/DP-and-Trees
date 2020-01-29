// https://leetcode.com/problems/longest-palindromic-subsequence/

// Recursion without memo
class Solution
{
public:
  int lps(string str, int s, int e)
  {

    int length = e - s + 1;

    if (length == 1)
    {
      return 1;
    }

    if (length == 2)
    {
      if (str[s] == str[e])
      {
        return 2;
      }
      else
      {
        return 1;
      }
    }

    if (str[s] == str[e])
    {
      return 2 + lps(str, s + 1, e - 1);
    }
    else
    {
      return max(lps(str, s + 1, e), lps(str, s, e - 1));
    }
  }

  int longestPalindromeSubseq(string s)
  {

    int n = s.length();

    return lps(s, 0, n - 1);
  }
};

// Recursion+Memo

class Solution
{
public:
  int lps(string &str, vector<vector<int>> &dp, int s, int e)
  {

    int l = e - s + 1;

    if (l == 1)
    {
      return 1;
    }

    if (l == 2)
    {
      if (str[s] == str[e])
      {
        return 2;
      }
      else
      {
        return 1;
      }
    }

    if (dp[s][e] == -1)
    {

      if (str[s] == str[e])
      {
        dp[s][e] = 2 + lps(str, dp, s + 1, e - 1);
      }
      else
      {
        dp[s][e] = max(lps(str, dp, s, e - 1), lps(str, dp, s + 1, e));
      }
    }
    return dp[s][e];
  }

  int longestPalindromeSubseq(string s)
  {

    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        dp[i][j] = -1;
      }
    }
    return lps(s, dp, 0, n - 1);
  }
};