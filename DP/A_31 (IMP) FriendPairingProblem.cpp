// https : //practice.geeksforgeeks.org/problems/friends-pairing-problem/0
#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
long long int help(int n)
{

  if (n <= 2)
  {
    return n;
  }

  vector<long long int> dp(n + 2);
  for (int i = 0; i <= n + 1; i++)
  {
    if (i <= 2)
      dp[i] = i;
    else
      dp[i] = -1;
  }

  for (int i = 3; i <= n; i++)
  {
    dp[i] = (dp[i - 1] + ((i - 1) * dp[i - 2]) % m) % m;
  }
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
    cout << help(n) << endl;
  }
}