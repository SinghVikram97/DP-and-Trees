// https://leetcode.com/problems/dungeon-game/

// Recursive
class Solution
{
public:
  int backtrack(vector<vector<int>> &v, int i, int j)
  {

    int m = v.size();
    int n = v[0].size();

    if (i >= m || j >= n)
    {
      return INT_MAX - 1000;
    }

    if (i == m - 1 && j == n - 1)
    {
      if (v[i][j] < 0)
      {
        // If knight starts at last cell
        // As long as he has health>0 when he reaches last cell he can survive
        // ie 6-5=1
        // so
        return abs(v[i][j]) + 1; //6
      }
      else
      {
        // Already health positive so just needs to be 1 to stay alive
        // If he reaches with 0 then he is already dead
        return 1;
      }
    }

    int left = backtrack(v, i + 1, j);
    int right = backtrack(v, i, j + 1);

    // If knight starts from cell 1 then he needs 6 at last cell
    // So 1+x should be 6
    // x=6-1 // left-v[i][j]

    // If less than 1 ,
    // Ex -5 at last cell returns 6
    // 6-30=-24  means already greater than what's needed so just need 1

    int minLeftHealthStart = left - v[i][j] <= 0 ? 1 : left - v[i][j];
    int minRightHealthStart = right - v[i][j] <= 0 ? 1 : right - v[i][j];

    return min(minLeftHealthStart, minRightHealthStart);
  }

  int calculateMinimumHP(vector<vector<int>> &dungeon)
  {

    return backtrack(dungeon, 0, 0);
  }
};

// Memoize recursive
class Solution
{
public:
  int backtrack(vector<vector<int>> &v, int i, int j, vector<vector<int>> &dp)
  {

    int m = v.size();
    int n = v[0].size();

    if (i >= m || j >= n)
    {
      return INT_MAX - 1000;
    }

    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }

    if (i == m - 1 && j == n - 1)
    {
      if (v[i][j] < 0)
      {
        // If knight starts at last cell
        // As long as he has health>0 when he reaches last cell he can survive
        // ie 6-5=1
        // so
        return abs(v[i][j]) + 1; //6
      }
      else
      {
        // Already health positive so just needs to be 1 to stay alive
        // If he reaches with 0 then he is already dead
        return 1;
      }
    }

    int left = backtrack(v, i + 1, j, dp);
    int right = backtrack(v, i, j + 1, dp);

    // If knight starts from cell 1 then he needs 6 at last cell
    // So 1+x should be 6
    // x=6-1 // left-v[i][j]

    // If less than 1 ,
    // Ex -5 at last cell returns 6
    // 6-30=-24  means already greater than what's needed so just need 1

    int minLeftHealthStart = left - v[i][j] <= 0 ? 1 : left - v[i][j];
    int minRightHealthStart = right - v[i][j] <= 0 ? 1 : right - v[i][j];

    dp[i][j] = min(minLeftHealthStart, minRightHealthStart);

    return dp[i][j];
  }

  int calculateMinimumHP(vector<vector<int>> &dungeon)
  {

    int m = dungeon.size();
    int n = dungeon[0].size();

    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        dp[i][j] = -1;
      }
    }
    return backtrack(dungeon, 0, 0, dp);
  }
};