// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
#define m 1000000007
class Solution
{
public:
  int help(int d, int index, int f, int target, vector<vector<int>> &dp)
  {

    if (index == d && target == 0)
    {
      return 1;
    }

    if (index == d || target == 0)
    {
      return 0;
    }

    if (target < 0)
    {
      return 0;
    }

    if (dp[index][target] != -1)
    {
      return dp[index][target];
    }

    int ans = 0;
    for (int i = 1; i <= f; i++)
    {
      ans = ((ans % m) + (help(d, index + 1, f, target - i, dp)) % m) % m;
    }

    dp[index][target] = ans % m;

    return dp[index][target];
  }

  int numRollsToTarget(int d, int f, int target)
  {

    vector<vector<int>> dp(d + 1, vector<int>(target + 1));

    for (int i = 0; i <= d; i++)
    {
      for (int j = 0; j <= target; j++)
      {
        dp[i][j] = -1;
      }
    }

    return help(d, 0, f, target, dp);
  }
};