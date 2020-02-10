//https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0

#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
void help(vector<long long int> &dp)
{

  int n = dp.size();

  vector<long long int> a(n); // Bit string having no consecutive 1's ending with 0
  vector<long long int> b(n); // Bit string having no consective 1's ending with 1

  a[0] = 0;
  a[1] = 1;
  b[0] = 0;
  b[1] = 1;

  dp[0] = a[0] + b[0];
  dp[1] = a[1] + b[1];

  // Bit string ending with 0 can put 1 or 0 at it's end to increase length
  // Bit string ending with 1 can put only 0 at its end to increase length

  for (int i = 2; i < n; i++)
  {

    // New string ending with 0 are putting 0 at strings ending with 0 and 1
    a[i] = ((a[i - 1] % m) + (b[i - 1] % m)) % m;

    // New strings ending with 1 are putting 1 at strings ending with 0
    b[i] = (a[i - 1]) % m;

    // Total answer
    dp[i] = ((a[i] % m) + (b[i] % m)) % m;
  }
}
int main()
{

  int t;
  cin >> t;
  vector<long long int> dp(105);
  help(dp);
  while (t--)
  {

    int n;
    cin >> n;
    cout << dp[n] << endl;
  }
}