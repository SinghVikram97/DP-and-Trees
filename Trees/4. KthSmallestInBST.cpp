// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution
{
public:
  void kthSmallestHelper(TreeNode *root, int &ans, int &k)
  {

    if (root == NULL)
    {
      return;
    }
    if (k > 0)
    {
      kthSmallestHelper(root->left, ans, k);
    }
    // Visited a node decrease k
    k--;
    if (k == 0)
    {
      ans = root->val;
      return; // Doesn't stop the traversal when k becomes zero
    }
    if (k > 0)
    {
      kthSmallestHelper(root->right, ans, k);
    }
  }
  int kthSmallest(TreeNode *root, int k)
  {
    int ans;
    kthSmallestHelper(root, ans, k);
    return ans;
  }
};