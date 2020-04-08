#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &keys, vector<int> &freq, int i, int j, vector<vector<int>> &dp)
{

  if (i == j)
  {
    return freq[i];
  }

  if (i > j)
  {
    return 0;
  }

  if (dp[i][j] == -1)
  {
    // Choose every key from i to j as root
    // Sum freq from i to j as every search will go through root so it will add one time and so on till the key searched for
    int freqSum = 0;

    for (int k = i; k <= j; k++)
    {
      freqSum += freq[k];
    }

    // Now choose every key from i to j as root
    int min_cost = INT_MAX - 5;
    for (int k = i; k <= j; k++)
    {
      // cost is left+right
      min_cost = min(min_cost, helper(keys, freq, i, k - 1, dp) + helper(keys, freq, k + 1, j, dp));
    }

    dp[i][j] = min_cost + freqSum;
  }
  return dp[i][j];
}
int optimalBST(vector<int> &keys, vector<int> &freq, int n)
{

  // Every key in sorted array can be a root

  vector<vector<int>> dp(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      dp[i][j] = -1;
    }
  }

  return helper(keys, freq, 0, n - 1, dp);
}
int main()
{

  int n;
  cin >> n;

  // Sorted array of keys
  vector<int> keys(n);
  for (int i = 0; i < n; i++)
  {
    cin >> keys[i];
  }

  // Freq of search for each key
  // freq[i] is freq of search for key[i]
  vector<int> freq(n);
  for (int i = 0; i < n; i++)
  {
    cin >> freq[i];
  }

  cout << optimalBST(keys, freq, n) << endl;
}