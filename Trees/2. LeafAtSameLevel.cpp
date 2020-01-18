// Check if all leaves at same level
//https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
// Do level order traversal and if a leaf node
// See if we have already seen a leaf at some other level

bool check(Node *root)
{

  queue<Node *> mq;
  mq.push(root);
  mq.push(NULL);
  int level = -1;
  int cl = 0;

  while (!mq.empty())
  {
    Node *front = mq.front();
    mq.pop();

    if (front != NULL)
    {
      if (front->left == NULL && front->right == NULL)
      {

        if (level == -1)
        {
          level = cl;
        }
        else
        {
          if (level != cl)
          {
            return false;
          }
        }
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
      if (!mq.empty())
      {
        cl++;
        mq.push(NULL);
      }
    }
  }
  return true;
}