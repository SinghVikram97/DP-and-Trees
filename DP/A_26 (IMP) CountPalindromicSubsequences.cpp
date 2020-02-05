// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
// Recursion
int help(string &s, int i, int j)
{

  if (i > j)
  {
    return 0;
  }

  if (i == j)
  {
    return 1;
  }

  // 1st and last character same so it is a palindromic subsequence
  // Now we check for other subsequences
  if (s[i] == s[j])
  {
    return 1 + help(s, i + 1, j) + help(s, i, j - 1);
  }

  // Check other subsequences
  // IMPPPPPPPPPPP
  // Remove common subsequences as they are counted twice so - help(s,i+1,j-1)
  else
  {
    return help(s, i + 1, j) + help(s, i, j - 1) - help(s, i + 1, j - 1);
  }
}

int countPS(string str)
{
  int n = str.length();
  return help(str, 0, n - 1);
}

// Recursion + Memo
#include <bits/stdc++.h>
using namespace std;
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

int countPS(string str)
{
  int n = str.length();
  vector<vector<int>> dp(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      dp[i][j] = -1;
    }
  }
  return help(str, 0, n - 1, dp);
}
