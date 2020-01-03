//https://leetcode.com/problems/binary-tree-inorder-traversal/

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
  vector<int> inorderTraversal(TreeNode *root)
  {

    vector<int> ans;

    stack<TreeNode *> ms;

    TreeNode *cur = root;

    while (cur != NULL || !ms.empty())
    {

      while (cur != NULL)
      {
        ms.push(cur);
        cur = cur->left;
      }

      // Cur is null here
      cur = ms.top();
      ms.pop();

      ans.push_back(cur->val);

      cur = cur->right;
    }

    return ans;
  }
};