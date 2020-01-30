// http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
// https://hack.codingblocks.com/contests/c/141/1090

// Basic recursion

#include <bits/stdc++.h>
using namespace std;
int maximum_cost(int length_of_rod, vector<int> prices)
{
  if (length_of_rod == 0)
  {
    return 0;
  }
  int maximum = -1;
  /// At each step we can take portion of 1 to length of rod part from rod and sell it.
  /// We can take piece of length=1,2,3,....length_of_rod and calculate for remaining length
  for (int i = 1; i <= length_of_rod; i++)
  {
    maximum = max(maximum, maximum_cost(length_of_rod - i, prices) + prices[i]);
  }
  return maximum;
}
int main()
{
  int length_of_rod;
  cin >> length_of_rod;
  vector<int> prices(length_of_rod + 1); /// 1 based indexing
  for (int i = 1; i <= length_of_rod; i++)
  {
    cin >> prices[i];
  }
  cout << maximum_cost(length_of_rod, prices);
}

// Recursion + memo

#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int maximum_cost(int length_of_rod, vector<int> prices)
{
  if (length_of_rod == 0)
  {
    return 0;
  }
  if (dp[length_of_rod] == -1)
  {
    int maximum = -1;
    /// At each step we can take portion of 1 to length of rod part from rod and sell it.
    /// We can take piece of length=1,2,3,....length_of_rod and calculate for remaining length
    for (int i = 1; i <= length_of_rod; i++)
    {
      maximum = max(maximum, maximum_cost(length_of_rod - i, prices) + prices[i]);
    }
    dp[length_of_rod] = maximum;
  }
  return dp[length_of_rod];
}
int main()
{
  int length_of_rod;
  cin >> length_of_rod;
  for (int i = 0; i <= length_of_rod; i++)
  {
    dp[i] = -1;
  }
  vector<int> prices(length_of_rod + 1); /// 1 based indexing
  for (int i = 1; i <= length_of_rod; i++)
  {
    cin >> prices[i];
  }
  cout << maximum_cost(length_of_rod, prices);
}