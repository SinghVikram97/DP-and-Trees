// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// If tree can be modified store count of left nodes seperately
class Solution
{
public:
  int countLeftSubtreeNodes(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    return 1 + countLeftSubtreeNodes(root->left) + countLeftSubtreeNodes(root->right);
  }

  int kthSmallest(TreeNode *root, int k)
  {

    if (root == NULL)
    {
      return -1;
    }

    int n = countLeftSubtreeNodes(root->left);

    if (n + 1 == k)
    {
      // Root hi hai
      return root->val;
    }
    else if (n >= k)
    {
      // Left mein hai
      return kthSmallest(root->left, k);
    }
    else
    {
      // Right mein hai
      return kthSmallest(root->right, k - n - 1);
    }
  }
};