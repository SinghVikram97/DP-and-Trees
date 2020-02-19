
// Overflows for larger numbers

#include <bits/stdc++.h>
using namespace std;

unsigned long long int help(int n, int r)
{

  if (n < r)
  {
    return 0;
  }

  if (r == 0)
  {
    return 1;
  }

  if (r == 1)
  {
    return n;
  }

  // nCr=nCn-r
  if (r > n - r)
  {
    r = n - r;
  }

  unsigned long long int result = 1;

  // n(n-1)(n-2).....(n-r+1)/(1)(2).....(r)
  for (int i = 0; i < r; i++)
  {
    result = (result) * ((n - i) / (i + 1));
  }

  return result;
}
int main()
{

  int t;
  cin >> t;
  while (t--)
  {

    int n;
    cin >> n;
    int r;
    cin >> r;
    cout << help(n, r) << endl;
  }
}

// Recursion
// NcR=(N-1)c(R-1)+(N-1)c(R)
unsigned long long int help(int n, int r)
{

  if (n < r)
  {
    return 0;
  }

  if (r == 0)
  {
    return 1;
  }

  if (r == 1)
  {
    return n;
  }

  // nCr=nCn-r
  if (r > n - r)
  {
    r = n - r;
  }

  return help(n - 1, r - 1) + help(n - 1, r);
}

//  DP

#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
unsigned long long int help(int n, int r, vector<vector<unsigned long long int>> &dp)
{

  if (n == r || r == 0 || n == 1)
  {
    return 1;
  }

  if (r == 1)
  {
    return n;
  }

  if (dp[n][r] != -1)
  {
    return dp[n][r];
  }

  dp[n][r] = (help(n - 1, r, dp) % M + help(n - 1, r - 1, dp) % M) % M;

  return dp[n][r] % M;
}
int main()
{

  int t;
  cin >> t;
  while (t--)
  {

    int n, r;
    cin >> n >> r;

    if (r > n)
    {
      cout << 0 << endl;
    }
    else
    {
      vector<vector<unsigned long long int>> dp(n + 1, vector<unsigned long long int>(r + 1));
      for (int i = 0; i <= n; i++)
      {
        for (int j = 0; j <= r; j++)
        {
          dp[i][j] = -1;
        }
      }
      cout << help(n, r, dp) << endl;
    }
  }
}