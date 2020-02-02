// https://www.hackerrank.com/challenges/unbounded-knapsack/problem
#include <bits/stdc++.h>

using namespace std;

int help(vector<int> &arr, int capacity, int index)
{

  int n = arr.size();

  if (capacity == 0)
  {
    return 0;
  }

  if (index >= n)
  {
    return 0;
  }

  // Can pick or don't pick

  int op1 = 0;
  int op2 = 0;

  // Pick
  if (arr[index] <= capacity)
  {
    op1 = arr[index] + help(arr, capacity - arr[index], index);
  }

  // Don't pick

  op2 = help(arr, capacity, index + 1);

  return max(op1, op2);
}

// Complete the unboundedKnapsack function below.
int unboundedKnapsack(int k, vector<int> arr)
{

  return help(arr, k, 0);
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    cout << unboundedKnapsack(k, v) << endl;
  }

  return 0;
}
