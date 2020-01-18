// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Full Node is a node which has both left and right children
// Once a node is found which isn't a full node
// All other nodes should be leaf nodes
// Also if there is a right child left child can't be empty
// To handle case
//     1
//   /   \
//  2     3
//   \
//    4
class Solution
{
public:
  bool isCompleteTree(TreeNode *root)
  {

    queue<TreeNode *> mq;

    mq.push(root);

    bool notFullFound = false;

    while (!mq.empty())
    {

      TreeNode *front = mq.front();
      mq.pop();

      if (front->right && !front->left)
      {
        return false;
      }

      if (notFullFound)
      {
        // Every node should be a leaf node
        if (front->left || front->right)
        {
          return false;
        }
      }
      else
      {

        if (front->left && front->right)
        {
        }
        else
        {
          notFullFound = true;
        }

        if (front->left)
        {
          mq.push(front->left);
        }

        if (front->right)
        {
          mq.push(front->right);
        }
      }
    }
    return true;
  }
};