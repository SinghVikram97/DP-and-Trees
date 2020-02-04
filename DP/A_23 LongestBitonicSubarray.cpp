// https://practice.geeksforgeeks.org/problems/maximum-length-bitonic-subarray/0
#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &v, int n)
{

  // Max increasing subarray from start ending at i
  vector<int> left(n);

  left[0] = 1;

  for (int i = 1; i < n; i++)
  {

    if (v[i] > v[i - 1])
    {
      left[i] = left[i - 1] + 1;
    }
    else
    {
      left[i] = 1;
    }
  }

  // Max increasing subarray from end ending at i
  vector<int> right(n);

  right[n - 1] = 1;

  for (int i = n - 2; i >= 0; i--)
  {
    if (v[i] > v[i + 1])
    {
      right[i] = right[i + 1] + 1;
    }
    else
    {
      right[i] = 1;
    }
  }

  int final_ans = -1;

  for (int i = 0; i < n; i++)
  {
    final_ans = max(final_ans, left[i] + right[i] - 1);
  }

  return final_ans;
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