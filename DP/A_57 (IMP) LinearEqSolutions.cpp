#include <bits/stdc++.h>
using namespace std;
// Same as coin change/combination sum with infinite supply of each coefficient to make target sum=rhs
// Apply dp here
int help(vector<int> &coeff, int i, int rhs)
{

  if (rhs == 0)
  {
    return 1;
  }

  if (rhs < 0)
  {
    return 0;
  }

  if (i >= coeff.size())
  {
    return 0;
  }

  // Can take or not take
  int ans = 0;

  // take
  ans = ans + help(coeff, i, rhs - coeff[i]);

  // don't take
  ans = ans + help(coeff, i + 1, rhs);

  return ans;
}
int main()
{

  int n;
  cin >> n;

  vector<int> coeff(n);
  for (int i = 0; i < n; i++)
  {
    cin >> coeff[i];
  }

  int rhs;
  cin >> rhs;

  cout << help(coeff, 0, rhs) << endl;
}