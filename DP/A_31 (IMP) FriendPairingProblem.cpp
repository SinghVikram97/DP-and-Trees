// https : //practice.geeksforgeeks.org/problems/friends-pairing-problem/0
#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
long long int help(int n, vector<long long int> &dp)
{

  if (n <= 2)
  {
    return n;
  }

  if (dp[n] != -1)
  {
    return dp[n];
  }

  // Nth person can remain single --> f(n-1)
  // Or can pair up with any (n-1) people --> (n-1)*f(n-2)
  dp[n] = (help(n - 1, dp) + ((n - 1) * help(n - 2, dp)) % m) % m;

  return dp[n] % m;
}
int main()
{

  int t;
  cin >> t;
  while (t--)
  {

    int n;
    cin >> n;
    vector<long long int> dp(n + 2);
    for (int i = 0; i <= n + 1; i++)
    {
      dp[i] = -1;
    }
    cout << help(n, dp) << endl;
  }
}