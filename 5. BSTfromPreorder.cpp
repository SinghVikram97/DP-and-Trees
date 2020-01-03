// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// O(n2) naive

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
  TreeNode *bstFromPre(vector<int> &preorder, int s, int e)
  {

    if (s > e)
    {
      return NULL;
    }

    int n = e - s + 1;

    if (n == 0)
    {
      return NULL;
    }

    if (n == 1)
    {
      TreeNode *newNode = new TreeNode(preorder[s]);
      return newNode;
    }

    // Root is start element

    int rootVal = preorder[s];

    TreeNode *root = new TreeNode(rootVal);

    // Find 1st greatest element greater than root
    int rightStart = e + 1;

    for (int i = s; i <= e; i++)
    {
      if (preorder[i] > rootVal)
      {
        rightStart = i;
        break;
      }
    }

    root->left = bstFromPre(preorder, s + 1, rightStart - 1);
    root->right = bstFromPre(preorder, rightStart, e);

    return root;
  }

  TreeNode *bstFromPreorder(vector<int> &preorder)
  {

    return bstFromPre(preorder, 0, preorder.size() - 1);
  }
};