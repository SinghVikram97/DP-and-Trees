#include <bits/stdc++.h>
using namespace std;
int help(int n, int k, vector<vector<int>> &dp)
{

  if (k == 0)
  {
    return 0;
  }

  if (k == 1)
  {
    return 1;
  }

  if (n == 0)
  {
    return 0;
  }

  if (k == n)
  {
    return 1;
  }

  if (k > n)
  {
    return 0;
  }

  if (dp[n][k] != -1)
  {
    return dp[n][k];
  }

  /// Let (n)th number is to be inserted in k distinct set
  /// Either (n)th number can form its own single number set
  /// So f(n-1,k-1) (k-1 sets formed by n-1 elements and 1 by nth element)
  // Or it can be inserted into any existing k sets
  // so k*f(n-1,k)  (K sets formed by n-1 elements and add nth in any one)

  dp[n][k] = help(n - 1, k - 1, dp) + (k * help(n - 1, k, dp));
  return dp[n][k];
}
int main()
{

  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 5, vector<int>(k + 5));
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      dp[i][j] = -1;
    }
  }
  cout << help(n, k, dp) << endl;
}