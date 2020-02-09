// https://leetcode.com/problems/partition-equal-subset-sum/

// Recursion
class Solution
{
public:
  bool help(vector<int> &nums, int i, int sum1, int sum2)
  {

    if (i == nums.size())
    {
      if (sum1 == sum2)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    return help(nums, i + 1, sum1 + nums[i], sum2) || help(nums, i + 1, sum1, sum2 + nums[i]);
  }

  bool canPartition(vector<int> &nums)
  {
    return help(nums, 0, 0, 0);
  }
};

// Recursion 2
class Solution
{
public:
  bool help(vector<int> &v, int i, int targetSum)
  {

    int n = v.size();

    if (targetSum == 0)
    {
      return true;
    }

    if (i == n)
    {
      return false;
    }

    return help(v, i + 1, targetSum) + help(v, i + 1, targetSum - v[i]);
  }

  bool canPartition(vector<int> &v)
  {

    // Calculate sum of all numbers
    int sum = 0;

    for (auto num : v)
    {
      sum += num;
    }

    // If sum is odd can't divide in 2
    if (sum % 2 != 0)
    {
      return false;
    }

    // Else find a subset whose sum is equal to sum/2
    // If able to find then can partition else no

    return help(v, 0, sum / 2);
  }
};

// Recursion + Memo
class Solution
{
public:
  bool help(vector<int> &v, int i, int targetSum, vector<vector<int>> &dp)
  {

    int n = v.size();

    if (targetSum == 0)
    {
      return true;
    }

    if (i == n || targetSum < 0)
    {
      return false;
    }

    if (dp[i][targetSum] == -1)
    {
      dp[i][targetSum] = help(v, i + 1, targetSum, dp) || help(v, i + 1, targetSum - v[i], dp);
    }

    return dp[i][targetSum];
  }

  bool canPartition(vector<int> &v)
  {

    // Calculate sum of all numbers
    int sum = 0;

    for (auto num : v)
    {
      sum += num;
    }

    // If sum is odd can't divide in 2
    if (sum % 2 != 0)
    {
      return false;
    }

    // Else find a subset whose sum is equal to sum/2
    // If able to find then can partition else no

    int m = v.size();
    int n = (sum / 2);

    vector<vector<int>> dp(m + 5, vector<int>(n + 5));

    for (int i = 0; i < m + 5; i++)
    {
      for (int j = 0; j < n + 5; j++)
      {
        dp[i][j] = -1;
      }
    }

    return help(v, 0, sum / 2, dp);
  }
};