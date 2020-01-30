// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {

    int n = nums.size();

    if (n == 0)
    {
      return 0;
    }

    vector<int> dp(n);

    // dp[i] is lis ending at i

    for (int i = 0; i < n; i++)
    {

      dp[i] = 1;

      for (int j = i; j >= 0; j--)
      {

        if (nums[j] < nums[i])
        {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
    }

    // Find max length subsequence
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};