//https: //leetcode.com/problems/sum-of-left-leaves/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  int sum(TreeNode *root, bool isLeft)
  {

    if (root == NULL)
    {
      return 0;
    }

    else if (root->left == NULL && root->right == NULL)
    {
      if (isLeft)
      {
        return root->val;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return sum(root->left, true) + sum(root->right, false);
    }
  }
  int sumOfLeftLeaves(TreeNode *root)
  {
    return sum(root, false);
  }
};