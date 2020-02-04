// https://leetcode.com/problems/longest-common-subsequence/

// Recursion
class Solution
{
public:
  int help(string &s1, string &s2, int i, int j)
  {

    int n1 = s1.length();
    int n2 = s2.length();

    if (i == n1 || j == n2)
    {
      return 0;
    }

    if (s1[i] == s2[j])
    {
      return 1 + help(s1, s2, i + 1, j + 1);
    }

    else
    {
      return max(help(s1, s2, i + 1, j), help(s1, s2, i, j + 1));
    }
  }

  int longestCommonSubsequence(string text1, string text2)
  {
    return help(text1, text2, 0, 0);
  }
};

// Recursion + Memo
class Solution
{
public:
  int help(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
  {

    int n1 = s1.length();
    int n2 = s2.length();

    if (i == n1 || j == n2)
    {
      return 0;
    }

    if (dp[i][j] == -1)
    {

      if (s1[i] == s2[j])
      {
        dp[i][j] = 1 + help(s1, s2, i + 1, j + 1, dp);
      }

      else
      {
        dp[i][j] = max(help(s1, s2, i + 1, j, dp), help(s1, s2, i, j + 1, dp));
      }
    }

    return dp[i][j];
  }

  int longestCommonSubsequence(string text1, string text2)
  {

    int n1 = text1.length();
    int n2 = text2.length();

    vector<vector<int>> dp(n1, vector<int>(n2));

    for (int i = 0; i < n1; i++)
    {
      for (int j = 0; j < n2; j++)
      {
        dp[i][j] = -1;
      }
    }

    return help(text1, text2, 0, 0, dp);
  }
};