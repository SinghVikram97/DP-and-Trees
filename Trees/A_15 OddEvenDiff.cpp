// https://www.interviewbit.com/problems/difference-between-odd-and-even-levels/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode *A)
{

  int oddSum = 0;
  int evenSum = 0;

  queue<TreeNode *> mq;
  mq.push(A);
  mq.push(NULL);

  int level = 1;

  while (!mq.empty())
  {

    TreeNode *front = mq.front();
    mq.pop();

    if (front != NULL)
    {

      if (level % 2 == 0)
      {
        evenSum += front->val;
      }
      else
      {
        oddSum += front->val;
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
    else
    {

      level++;

      if (!mq.empty())
      {
        mq.push(NULL);
      }
    }
  }

  return oddSum - evenSum;
}
