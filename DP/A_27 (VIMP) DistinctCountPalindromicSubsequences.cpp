class Solution
{
public:
  int help(string &s, int i, int j, vector<vector<int>> &dp)
  {

    if (i > j)
    {
      return 0;
    }

    if (i == j)
    {
      return 1;
    }

    if (dp[i][j] == -1)
    {
      if (s[i] == s[j])
      {
        dp[i][j] = 1 + help(s, i + 1, j, dp) + help(s, i, j - 1, dp);
      }

      else
      {
        dp[i][j] = help(s, i + 1, j, dp) + help(s, i, j - 1, dp) - help(s, i + 1, j - 1, dp);
      }
    }
    return dp[i][j];
  }
  int countPalindromicSubsequences(string s)
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

    return help(s, 0, n - 1, dp);
  }
};