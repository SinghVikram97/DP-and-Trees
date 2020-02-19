// https://practice.geeksforgeeks.org/problems/nth-catalan-number/0

// 1) Count the number of expressions containing n pairs of parentheses which are correctly matched.
// For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

// 2) Count the number of possible Binary Search Trees with n keys

// 3) Count the number of full binary trees
// (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.

// The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
#include <bits/stdc++.h>
using namespace std;
int help(int n, vector<unsigned long long int> &dp)
{

  if (n == 0 || n == 1)
  {
    return 1;
  }

  if (dp[n] != -1)
  {
    return dp[n];
  }

  unsigned long long int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += help(i, dp) * help(n - i - 1, dp);
  }
  dp[n] = ans;
  return dp[n];
}
int main()
{

  int t;
  cin >> t;
  while (t--)
  {

    int n;
    cin >> n;
    vector<unsigned long long int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
      dp[i] = -1;
    }
    cout << help(n, dp) << endl;
  }
}