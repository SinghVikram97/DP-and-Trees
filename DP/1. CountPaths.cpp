// https://leetcode.com/problems/unique-paths/

// Recursion
class Solution
{
public:
  void countPaths(int i, int j, int m, int n, int &ans)
  {

    if (i == m - 1 && j == n - 1)
    {
      ans++;
      return;
    }

    if (i < 0 || i >= m)
    {
      return;
    }

    if (j < 0 || j >= n)
    {
      return;
    }

    countPaths(i + 1, j, m, n, ans);
    countPaths(i, j + 1, m, n, ans);

    return;
  }

  int uniquePaths(int m, int n)
  {
    int ans = 0;
    countPaths(0, 0, m, n, ans);
    return ans;
  }
};

// DP
class Solution
{
public:
  int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
  {

    if (i == m - 1 && j == n - 1)
    {
      // Path found
      return 1;
    }

    if (i < 0 || i >= m)
    {
      // Incorrect path
      return 0;
    }

    if (j < 0 || j >= n)
    {
      // Incorrect path
      return 0;
    }

    if (dp[i][j] == -1)
    {
      int ans = 0;
      ans += countPaths(i + 1, j, m, n, dp);
      ans += countPaths(i, j + 1, m, n, dp);
      dp[i][j] = ans;
    }
    return dp[i][j];
  }

  int uniquePaths(int m, int n)
  {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        dp[i][j] = -1;
      }
    }
    return countPaths(0, 0, m, n, dp);
  }
};