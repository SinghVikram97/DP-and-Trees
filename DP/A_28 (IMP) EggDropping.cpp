// https://leetcode.com/problems/super-egg-drop/submissions/

// Recursion
class Solution
{
public:
  int minimum_moves_worst_case(int numFloors, int numEggs)
  {

    // Only 1 floor to check
    if (numFloors == 1 || numFloors == 0)
    {
      return numFloors;
    }

    // Linearly check from bottom
    if (numEggs == 1)
    {
      return numFloors;
    }

    // Try dropping egg starting from every floor
    int ans = INT_MAX - 5;
    for (int i = 1; i <= numFloors; i++)
    {

      // Egg breaks or doesn't break
      // If egg breaks go downwards (currentFloor-1)
      // If doesn't break num of floors-currentFloor left or go upward

      // Minimum moves in worst case (take max inside)
      ans = min(ans,
                max(
                    1 + minimum_moves_worst_case(i - 1, numEggs - 1),
                    1 + minimum_moves_worst_case(numFloors - i, numEggs)));
    }
    return ans;
  }

  int superEggDrop(int K, int N)
  {
    return minimum_moves_worst_case(N, K);
  }
};

// Memo
class Solution
{
public:
  int minimum_moves_worst_case(int numFloors, int numEggs, vector<vector<int>> &dp)
  {

    // Only 1 floor to check
    if (numFloors == 1 || numFloors == 0)
    {
      return numFloors;
    }

    // Linearly check from bottom
    if (numEggs == 1)
    {
      return numFloors;
    }

    if (dp[numFloors][numEggs] == -1)
    {

      // Try dropping egg starting from every floor
      int ans = INT_MAX - 5;
      for (int i = 1; i <= numFloors; i++)
      {

        // Egg breaks or doesn't break
        // If egg breaks go downwards (currentFloor-1)
        // If doesn't break num of floors-currentFloor left or go upward

        // Minimum moves in worst case (take max inside)
        ans = min(ans,
                  max(
                      1 + minimum_moves_worst_case(i - 1, numEggs - 1, dp),
                      1 + minimum_moves_worst_case(numFloors - i, numEggs, dp)));
      }

      dp[numFloors][numEggs] = ans;
    }

    return dp[numFloors][numEggs];
  }

  int superEggDrop(int K, int N)
  {
    vector<vector<int>> dp(N + 1, vector<int>(K + 1));
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= K; j++)
      {
        dp[i][j] = -1;
      }
    }
    return minimum_moves_worst_case(N, K, dp);
  }
};