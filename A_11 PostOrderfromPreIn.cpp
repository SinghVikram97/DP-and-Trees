//https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0

// Construct tree and print

// Print post order of left then right then print root

void printPost(int pre[], int in[], int n)
{

  int rootIndex = searchRootInorder(pre[0], in, n);

  if (i != 0)
  {
    // Left subtree
    printPost(pre + 1, in, i);
  }

  if (i != n - 1)
  {
    printPost(pre + i + 1, in + i + 1, n - i - 1);
  }

  cout << pre[0] << " ";
}

int searchRootInorder(int rootData, int in[], int n)
{
  for (int i = 0; i < n; i++)
  {
    if (in[i] == rootData)
    {
      return i;
    }
  }
  return -1;
}