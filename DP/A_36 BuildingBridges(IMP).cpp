// https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
// https://stackoverflow.com/questions/7288585/building-bridges-problem-how-to-apply-longest-increasing-subsequence
#include <bits/stdc++.h>
using namespace std;
bool myComp(pair<int, int> &a, pair<int, int> &b)
{

  if (a.first < b.first)
  {
    return true;
  }
  else
  {
    return a.second < b.second;
  }
}
int solve(vector<pair<int, int>> &northSouth, int n)
{

  // lis ending at i is dp[i]
  vector<int> dp(n);

  for (int i = 0; i < n; i++)
  {
    // ending at number itself
    dp[i] = 1;

    for (int j = i - 1; j >= 0; j--)
    {
      if (northSouth[j].second < northSouth[i].second)
      {
        // length of lis ending at i can be 1+length of lis ending at j
        dp[i] = max(dp[i], 1 + dp[j]);
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

  int n;
  cin >> n;

  vector<pair<int, int>> northSouth(n);

  // North coordinates
  for (int i = 0; i < n; i++)
  {
    cin >> northSouth[i].first;
  }

  // South coordinates
  for (int i = 0; i < n; i++)
  {
    cin >> northSouth[i].second;
  }

  // Sort according to north candidates
  sort(northSouth.begin(), northSouth.end());

  // for (int i = 0; i < n; i++)
  // {
  //   cout << northSouth[i].first << " " << northSouth[i].second << endl;
  // }

  // Now apply lis on south coordinates

  cout << solve(northSouth, n) << endl;

  return 0;
}
