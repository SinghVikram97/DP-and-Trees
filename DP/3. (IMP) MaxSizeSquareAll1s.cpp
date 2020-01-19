// https://leetcode.com/problems/maximal-square/
// Dp[i][j] denotes max square ending at element matrix[i][j]
// it depends upon (i-1,j) (i,j-1) and (i-1,j-1)

class Solution
{
public:
  int maximalSquare(vector<vector<char>> &matrix)
  {

    if (matrix.size() == 0)
    {
      return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {

      for (int j = 0; j < n; j++)
      {

        mat[i][j] = matrix[i][j] - '0';
      }
    }

    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {

        int op1;
        int op2;
        int op3;

        if (i - 1 >= 0 && j - 1 >= 0)
        {
          op1 = dp[i - 1][j - 1];
        }
        else
        {
          op1 = 0;
        }

        if (i - 1 >= 0)
        {
          op2 = dp[i - 1][j];
        }
        else
        {
          op2 = 0;
        }

        if (j - 1 >= 0)
        {
          op3 = dp[i][j - 1];
        }
        else
        {
          op3 = 0;
        }

        if (mat[i][j] == 1)
        {
          dp[i][j] = mat[i][j] + min(op1, min(op2, op3));
        }
        else
        {
          dp[i][j] = 0;
        }
      }
    }

    int maxSide = -1;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        maxSide = max(maxSide, dp[i][j]);
      }
    }

    return maxSide * maxSide;
  }
};