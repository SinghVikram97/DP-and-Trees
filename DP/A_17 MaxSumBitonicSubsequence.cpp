// https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/

#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &v, int n)
{

  vector<int> left(n);

  for (int i = 0; i < n; i++)
  {
    left[i] = v[i];
    for (int j = i; j >= 0; j--)
    {
      if (v[j] < v[i])
      {
        left[i] = max(left[i], v[i] + left[j]);
      }
    }
  }

  vector<int> right(n);

  for (int i = n - 1; i >= 0; i--)
  {
    right[i] = v[i];
    for (int j = i; j < n; j++)
    {
      if (v[j] < v[i])
      {
        right[i] = max(right[i], v[i] + right[j]);
      }
    }
  }

  int ans = -1;

  for (int i = 0; i < n; i++)
  {

    ans = max(ans, left[i] + right[i] - v[i]);
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