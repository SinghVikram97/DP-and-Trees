// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &v, int n)
{

  // Same as LIS just store max sum subsequence ending at i in dp[i]

  vector<int> dp(n);

  for (int i = 0; i < n; i++)
  {
    dp[i] = v[i];
    for (int j = i; j >= 0; j--)
    {
      if (v[j] < v[i])
      {
        dp[i] = max(dp[i], v[i] + dp[j]);
      }
    }
  }

  int ans = -1;

  for (int i = 0; i < n; i++)
  {
    ans = max(ans, dp[i]);
  }

  return ans;
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

    cout << help(v, n) << endl;
  }
}