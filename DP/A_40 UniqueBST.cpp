// https://leetcode.com/problems/unique-binary-search-trees/submissions/
// nth catalan no is
// sum from 0 to n-1
// C(i)*C(n-i-1)
// 1,1,2,5,..........
class Solution
{
public:
  int help(int n, vector<int> &dp)
  {
    if (n == 0 || n == 1)
    {
      return 1;
    }
    if (dp[n] != -1)
    {
      return dp[n];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += help(i, dp) * help(n - i - 1, dp);
    }
    dp[n] = ans;
    return dp[n];
  }

  int numTrees(int n)
  {
    vector<int> dp(n + 5);
    for (int i = 0; i <= n; i++)
    {
      dp[i] = -1;
    }
    return help(n, dp);
  }
};