// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
/// ABCD
/// We consider A|BCD, AB|CD, ABC|D
/// No A|BC|D as multiplying BC and then multiplying A or D wouldn't be possible due to matrix conditions
#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &v, int i, int j, vector<vector<int>> &dp)
{

  // (ABC)=(AB)C=A(BC)
  // So put cursor or divide anywhere
  // So min operations to multiply these + operations to multiply
  // Both resultant matrices returned

  // Only 1 matrix
  if (i + 1 == j)
  {
    return 0;
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  int operations = -1;
  for (int k = i + 1; k < j; k++)
  {

    operations = max(operations, help(v, i, k, dp) + help(v, k, j, dp) + (v[i] * v[k] * v[j]));
  }
  dp[i][j] = operations;
  return dp[i][j];
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        dp[i][j] = -1;
      }
    }
    cout << help(v, 0, n - 1, dp) << endl;
  }
}