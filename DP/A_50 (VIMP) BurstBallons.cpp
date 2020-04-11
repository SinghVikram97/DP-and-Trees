// https://leetcode.com/problems/burst-balloons/

// If you think of bursting a balloon as multiplying two adjacent matrices,
// then this problem is exactly the classical DP problem Matrix-chain multiplication.

// For example, given [3,5,8] and bursting 5, the number of coins you get is the
// number of scalar multiplications you need to do to multiply two matrices A[3*5] and B[5*8].
// So in this example, the original problem is actually the same as given a matrix chain A[1*3]*B[3*5]*C[5*8]*D[8*1],
// fully parenthesize it so that the total number of scalar multiplications is maximized,
// Add 1 to both front and back of the array to have the matrix vector
// although the orignal matrix-chain multiplication problem asks to minimize it.
// Then you can see it clearly as a classical DP problem.

// We can't use recursion directly because
// [1,2,3] if we burst 2
// Then [1] and [3] remains which are smaller subproblems but not independent of each other
// As remaining array becomes [1,3]

class Solution
{
public:
  int help(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
  {

    if (i + 1 == j)
    {
      return 0;
    }

    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }

    int max_coins = -1;

    for (int k = i + 1; k < j; k++)
    {
      max_coins = max(max_coins, help(nums, i, k, dp) + help(nums, k, j, dp) + (nums[i] * nums[k] * nums[j]));
    }

    dp[i][j] = max_coins;

    return dp[i][j];
  }

  int maxCoins(vector<int> &nums)
  {

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        dp[i][j] = -1;
      }
    }

    return help(nums, 0, n - 1, dp);
  }
};