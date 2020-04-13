// https://leetcode.com/problems/house-robber/
class Solution
{
public:
  int rob(vector<int> &nums)
  {

    int n = nums.size();

    if (n == 0)
    {
      return 0;
    }

    if (n == 1)
    {
      return nums[0];
    }

    vector<int> dp(n);

    // dp[i] represents max sum ending at i
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {

      // for given i we can take it+dp[i-2]
      // Or leave it and just take dp[i-1]

      dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
  }
};