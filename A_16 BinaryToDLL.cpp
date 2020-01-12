// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
void helper(Node *root, Node **head_ref, Node *&prev)
{

  if (root == NULL)
  {
    return;
  }

  helper(root->left, head_ref, prev);

  if (prev == NULL)
  {
    *(head_ref) = root;
  }

  else
  {
    root->left = prev;
    prev->right = root;
  }

  prev = root;

  helper(root->right, head_ref, prev);
}
void bToDLL(Node *root, Node **head_ref)
{
  Node *prev = NULL;
  return helper(root, head_ref, prev);
}
