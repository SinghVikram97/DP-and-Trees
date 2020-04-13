// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0
// greedy doesn't work
// 8 15 3 7
#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &v, int i, int j, vector<vector<int>> &dp)
{

  // Base case
  if (i > j)
  {
    return 0;
  }

  if (i == j)
  {
    return v[i];
  }

  if (i + 1 == j)
  {
    return max(v[i], v[j]);
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  // User1 can take either i or jth coin

  // If he takes ith coin
  // User 2 can take i+1th coin -> so user1 will have to choose from (i+2,j)
  // Or User 2 can take jth coin -> so user1 will have to choose from (i+1,j-1)
  // Since User2 as smart as User1 he will take choice with maximum return
  // So user 1 will get minimum of the 2
  int op1 = v[i] + min(help(v, i + 2, j, dp), help(v, i + 1, j - 1, dp));

  // If he takes jth coin
  // User 2 can take ith coin -> so user1 will have to choose from (i+1,j-1)
  // Or User2 can take (j-1)th coin -> so user1 will have to choose from (i,j-2)
  // Since user2 as smart as User1 he will take one with maximum return
  // So User1 will get choice with minimum return
  int op2 = v[j] + min(help(v, i + 1, j - 1, dp), help(v, i, j - 2, dp));

  // Now User1 can take maximum of 2 choice available to him as he is smart as User2
  dp[i][j] = max(op1, op2);

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

  return 0;
}
