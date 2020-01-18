// https://leetcode.com/problems/minimum-path-sum

// Recursion
class Solution
{
public:
  void help(vector<vector<int>> &grid, int i, int j, int pathSum, int &finalAns)
  {

    int m = grid.size();
    int n = grid[0].size();

    if (i == m - 1 && j == n - 1)
    {
      pathSum += grid[i][j];
      finalAns = min(pathSum, finalAns);
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

    help(grid, i + 1, j, pathSum + grid[i][j], finalAns);
    help(grid, i, j + 1, pathSum + grid[i][j], finalAns);

    return;
  }

  int minPathSum(vector<vector<int>> &grid)
  {

    int finalAns = INT_MAX;

    help(grid, 0, 0, 0, finalAns);

    return finalAns;
  }
};

//DP

class Solution
{
public:
  long long int help(vector<vector<int>> &grid, int i, int j, vector<vector<long long int>> &dp)
  {

    int m = grid.size();
    int n = grid[0].size();

    if (i == m - 1 && j == n - 1)
    {
      return grid[i][j];
    }

    if (i < 0 || i >= m)
    {
      return INT_MAX - 5;
    }

    if (j < 0 || j >= n)
    {
      return INT_MAX - 5;
    }

    if (dp[i][j] == -1)
    {

      long long int op1 = grid[i][j] + help(grid, i + 1, j, dp);
      long long int op2 = grid[i][j] + help(grid, i, j + 1, dp);

      dp[i][j] = min(op1, op2);
    }

    return dp[i][j];
  }

  int minPathSum(vector<vector<int>> &grid)
  {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1));

    for (int i = 0; i <= m; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        dp[i][j] = -1;
      }
    }

    return help(grid, 0, 0, dp);
  }
};