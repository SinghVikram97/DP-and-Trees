// https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1
// Num nodes for case
// 1
//  \
//   2
//    \
//     3
void printCorner(Node *root)
{

  queue<Node *> mq;
  mq.push(root);
  mq.push(NULL);

  Node *prev = NULL;

  int level = 1;

  int numNodes = 0;

  while (!mq.empty())
  {

    Node *front = mq.front();
    mq.pop();

    if (front != NULL)
    {

      numNodes++;
      if (prev == NULL)
      {
        cout << front->key << " ";
      }
      if (front->left)
      {
        mq.push(front->left);
      }
      if (front->right)
      {
        mq.push(front->right);
      }
      prev = front;
    }
    else
    {

      if (!mq.empty())
      {
        if (numNodes > 1)
        {
          cout << prev->key << " ";
        }
        numNodes = 0;
        prev = NULL;
        mq.push(NULL);
        level++;
      }
    }
  }
  if (numNodes > 1)
  {
    cout << prev->key << " ";
  }
}