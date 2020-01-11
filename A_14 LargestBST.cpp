// https://www.interviewbit.com/problems/largest-bst-subtree/
// isBST,numNodes,minimum,maximum
pair<pair<bool, int>, pair<int, int>> helper(TreeNode *root, int &ans)
{

  if (root == NULL)
  {
    return make_pair(make_pair(true, 0), make_pair(INT_MAX, INT_MIN));
  }

  if (root->left == NULL && root->right == NULL)
  {
    ans = max(ans, 1);
    return make_pair(make_pair(true, 1), make_pair(root->val, root->val));
  }

  /// See if left and right subtree both BST then only possible

  pair<pair<bool, int>, pair<int, int>> p1 = helper(root->left, ans);
  pair<pair<bool, int>, pair<int, int>> p2 = helper(root->right, ans);

  int mini = min(root->val, min(p1.second.first, p2.second.first));
  int maxi = max(root->val, max(p1.second.second, p2.second.second));
  int numNodes = p1.first.second + p2.first.second + 1;

  if (p1.first.first && p2.first.first)
  {

    // Check if tree rooted at this node a bst
    // Root should be greater than maximum in left subtree
    // Root should be less than minimum in right subtree
    if (root->val > p1.second.second && root->val < p2.second.first)
    {
      ans = max(ans, numNodes);
      return make_pair(make_pair(true, numNodes), make_pair(mini, maxi));
    }
    else
    {
      return make_pair(make_pair(false, numNodes), make_pair(mini, maxi));
    }
  }
  else
  {
    return make_pair(make_pair(false, numNodes), make_pair(mini, maxi));
  }
}

int Solution::solve(TreeNode *A)
{

  int ans = -1;

  helper(A, ans);

  return ans;
}