// https://practice.geeksforgeeks.org/problems/pth-common-ancestor-in-bst/1
/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */

void traverse(int x, int y, NODE *root, vector<int> &temp)
{

  if (root == NULL)
  {
    return;
  }

  if (root->data == x || root->data == y)
  {

    if (root->left == NULL && root->right == NULL)
    {
      // If leaf do nothing
    }
    else
    {
      // Second node among x and y below this root so this root will be a ancestor
      // 1
      //  \
      //   2
      //    \
      //     3
      // For 2 and 3, 2 is 1st ancestor
      temp.push_back(root->data);
    }
    return;
  }

  temp.push_back(root->data);

  if (root->data < x && root->data < y)
  {
    traverse(x, y, root->right, temp);
  }

  else if (root->data > x && root->data > y)
  {
    traverse(x, y, root->left, temp);
  }
  else
  {
    // Root is 1st ancestor
    return;
  }
}

int pthCommonAncestor(int x, int y, NODE *root, int p, vector<int> &vec)
{

  vector<int> temp;

  traverse(x, y, root, temp);

  if (temp.size() - p < 0 || temp.size() - p > temp.size())
  {
    return -1;
  }

  return temp[temp.size() - p];
}