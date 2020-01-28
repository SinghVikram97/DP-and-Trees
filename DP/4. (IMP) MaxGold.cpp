// https://leetcode.com/problems/path-with-maximum-gold/

class Solution
{
public:
  int func(vector<vector<int>> &grid, int i, int j)
  {

    int m = grid.size();
    int n = grid[0].size();

    // Can't collect
    if (i < 0 || i >= m || j < 0 || j >= n)
    {
      return 0;
    }

    // If 0 can't collect
    if (grid[i][j] == 0)
    {
      return 0;
    }

    // Collect gold here and try to move in all directions
    int ans = grid[i][j];

    // Put 0 in grid[i][j] to avoid infinite recursion
    grid[i][j] = 0;

    int op1 = func(grid, i + 1, j);
    int op2 = func(grid, i, j + 1);
    int op3 = func(grid, i - 1, j);
    int op4 = func(grid, i, j - 1);

    int add = max({op1, op2, op3, op4});

    // Backtrack
    grid[i][j] = ans;

    return ans + add;
  }

  int getMaximumGold(vector<vector<int>> &grid)
  {

    int m = grid.size();
    int n = grid[0].size();
    int final_ans = -1;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {

        int temp_ans = func(grid, i, j);
        final_ans = max(final_ans, temp_ans);
      }
    }
    return final_ans;
  }
};