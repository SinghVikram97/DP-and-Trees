// https://practice.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst/0

#include <bits/stdc++.h>
using namespace std;
void printLeaf(vector<int> &pre, int s, int e)
{

  if (s > e)
  {
    return;
  }

  int n = e - s + 1;

  if (n == 0)
  {
    return;
  }

  if (n == 1)
  {
    cout << pre[s] << " ";
  }

  int root = pre[s];

  int rightStart = e + 1;

  for (int i = s; i <= e; i++)
  {
    if (pre[i] > root)
    {
      rightStart = i;
      break;
    }
  }

  printLeaf(pre, s + 1, rightStart - 1);
  printLeaf(pre, rightStart, e);
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
    printLeaf(v, 0, n - 1);
    cout << endl;
  }
}