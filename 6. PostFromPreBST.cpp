//https://www.geeksforgeeks.org/find-postorder-traversal-of-bst-from-preorder-traversal/

// Make BST from preorder and then print postorder - O(N^2)

// Range method

void findPostOrder(vector<int> pre)
{
  int preIndex = 0;
  int n = pre.size();
  findPostOrderHelp(pre, preIndex, n, INT_MIN, INT_MAX);
}

void findPostOrderHelp(vector<int> &pre, int &preIndex, int n, int minV, int maxV)
{
  if (preIndex == n)
  {
    return;
  }

  if (!(pre[preIndex] > minV && pre[preIndex] < maxV))
  {
    return;
  }

  int root = pre[preIndex];

  preIndex++;

  findPostOrderHelp(pre, preIndex, n, minV, root);
  findPostOrderHelp(pre, preIndex, n, root, maxV);

  cout << root << " ";
}