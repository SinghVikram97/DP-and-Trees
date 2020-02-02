// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

// Recursion
#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &values, vector<int> &weights, int capacity, int index)
{

  int n = values.size();

  if (capacity == 0)
  {
    return 0;
  }

  if (index >= n)
  {
    return 0;
  }

  // Either pick or don't pick
  // Can pick if its weight < capacity remaining

  int op1 = 0;
  int op2 = 0;

  if (weights[index] <= capacity)
  {

    op1 = values[index] + help(values, weights, capacity - weights[index], index + 1);
  }

  // Don't pick
  op2 = help(values, weights, capacity, index + 1);

  return max(op1, op2);
}
int main()
{

  int t;
  cin >> t;
  while (t--)
  {

    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
      cin >> values[i];
    }
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
      cin >> weights[i];
    }
    cout << help(values, weights, capacity, 0) << endl;
  }
}

// Recursion + Memo
#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &values, vector<int> &weights, int capacity, int index, vector<vector<int>> &dp)
{

  int n = values.size();

  if (capacity == 0)
  {
    return 0;
  }

  if (index >= n)
  {
    return 0;
  }

  if (dp[index][capacity] == -1)
  {
    // Either pick or don't pick
    // Can pick if its weight < capacity remaining

    int op1 = 0;
    int op2 = 0;

    if (weights[index] <= capacity)
    {

      op1 = values[index] + help(values, weights, capacity - weights[index], index + 1, dp);
    }

    // Don't pick
    op2 = help(values, weights, capacity, index + 1, dp);

    dp[index][capacity] = max(op1, op2);
  }

  return dp[index][capacity];
}
int main()
{

  int t;
  cin >> t;
  while (t--)
  {

    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
      cin >> values[i];
    }
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
      cin >> weights[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));

    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= capacity; j++)
      {
        dp[i][j] = -1;
      }
    }

    cout << help(values, weights, capacity, 0, dp) << endl;
  }
}