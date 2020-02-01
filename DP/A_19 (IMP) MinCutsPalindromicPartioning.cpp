// https://leetcode.com/problems/palindrome-partitioning-ii/

// Basic recursion
class Solution
{
public:
  bool isPalindrome(string str, int s, int e)
  {

    while (s <= e)
    {
      if (str[s] != str[e])
      {
        return false;
      }
      s++;
      e--;
    }
    return true;
  }

  int help(string &s, int i, int j)
  {

    if (i == j)
    {
      // Length is 1
      return 0;
    }

    // Whole string is palindrome
    if (isPalindrome(s, i, j))
    {
      return 0;
    }

    int ans = INT_MAX - 5;

    for (int k = i; k <= j - 1; k++)
    {
      // Cut string at k so 1 cut
      // Plus min cuts to make both left and right halves palindromes
      ans = min(ans, help(s, i, k) + 1 + help(s, k + 1, j));
    }

    return ans;
  }

  int minCut(string s)
  {

    int n = s.length();

    return help(s, 0, n - 1);
  }
};

// Recursion + Memo + Basic cases at start

class Solution
{
public:
  bool isPalindrome(string str, int s, int e)
  {

    while (s <= e)
    {
      if (str[s] != str[e])
      {
        return false;
      }
      s++;
      e--;
    }
    return true;
  }

  int help(string &s, int i, int j, vector<vector<int>> &dp)
  {

    if (i == j)
    {
      // Length is 1
      dp[i][j] = 0;
      return dp[i][j];
    }

    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }

    else
    {

      if (isPalindrome(s, i, j))
      {
        dp[i][j] = 0;
      }
      else
      {

        int ans = INT_MAX - 5;

        for (int k = i; k <= j - 1; k++)
        {
          ans = min(ans, help(s, i, k, dp) + 1 + help(s, k + 1, j, dp));
        }

        dp[i][j] = ans;
      }
    }

    return dp[i][j];
  }

  int minCut(string s)
  {

    int n = s.length();

    if (isPalindrome(s, 0, n - 1))
    {
      return 0;
    }

    // Add this to avoid TLE
    for (int i = 0; i < n; i++)
    {
      if (isPalindrome(s, 0, i) && isPalindrome(s, i + 1, n - 1))
      {
        return 1;
      }
    }

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