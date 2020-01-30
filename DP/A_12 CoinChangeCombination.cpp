// https://leetcode.com/problems/coin-change-2/

// Recursion

class Solution
{
public:
  int help(vector<int> &coins, int amount, int index)
  {

    int n = coins.size();

    if (amount == 0)
    {
      return 1;
    }

    if (amount < 0)
    {
      return 0;
    }

    if (index == n)
    {
      return 0;
    }

    int count = 0;

    count = count + help(coins, amount - coins[index], index);

    count = count + help(coins, amount, index + 1);

    return count;
  }

  int change(int amount, vector<int> &coins)
  {

    return help(coins, amount, 0);
  }
};

// Recursion + Memo

class Solution
{
public:
  int help(vector<int> &coins, int amount, int index, vector<vector<int>> &dp)
  {

    int n = coins.size();

    if (amount == 0)
    {
      return 1;
    }

    if (amount < 0)
    {
      return 0;
    }

    if (index == n)
    {
      return 0;
    }

    if (dp[index][amount] == -1)
    {

      int count = 0;

      count = count + help(coins, amount - coins[index], index, dp);

      count = count + help(coins, amount, index + 1, dp);

      dp[index][amount] = count;
    }
    return dp[index][amount];
  }

  int change(int amount, vector<int> &coins)
  {

    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= amount; j++)
      {
        dp[i][j] = -1;
      }
    }

    return help(coins, amount, 0, dp);
  }
};