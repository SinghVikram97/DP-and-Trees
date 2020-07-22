// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Basic recursive
class Solution
{
public:
  int help(string str, int s, int e)
  {

    if (s > e)
    {
      return 0;
    }

    if (s == e)
    {
      return 0;
    }

    if (str[s] == str[e])
    {
      return help(str, s + 1, e - 1);
    }
    else
    {
      return 1 + min(help(str, s + 1, e), help(str, s, e - 1));
    }
  }

  int minInsertions(string s)
  {

    int n = s.length();
    return help(s, 0, n - 1);
  }
};

// Dp
class Solution
{
public:
  vector<vector<int>> dp;
  int help(string &str, int s, int e)
  {

    if (s >= e)
    {
      return 0;
    }

    if (dp[s][e] != -1)
    {
      return dp[s][e];
    }

    return dp[s][e] = str[s] == str[e] ? help(str, s + 1, e - 1) : 1 + min(help(str, s + 1, e), help(str, s, e - 1));
  }

  int minInsertions(string s)
  {

    int n = s.length();

    dp.resize(n, vector<int>(n, -1));

    return help(s, 0, n - 1);
  }
};