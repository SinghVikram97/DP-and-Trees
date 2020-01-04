// https://leetcode.com/problems/validate-binary-search-tree/
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
  bool isValid(TreeNode *root, long long int minV, long long int maxV)
  {

    if (root == NULL)
    {
      return true;
    }

    if (!(root->val > minV && root->val < maxV))
    {
      return false;
    }
    else
    {
      return isValid(root->left, minV, root->val) && isValid(root->right, root->val, maxV);
    }
  }

  bool isValidBST(TreeNode *root)
  {
    return isValid(root, LONG_MIN, LONG_MAX);
  }
};