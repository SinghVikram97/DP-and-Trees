// Make binary tree from linked list

#include <bits/stdc++.h>
using namespace std;

TreeNode *(Node *head, TreeNode *root)
{

  // Store all the nodes in a vector
  vector<TreeNode *> v;
  Node *temp = head;

  while (temp != NULL)
  {
    TreeNode *newNode = new TreeNode(temp->Data);
    v.push_back(newNode);
    temp = temp.next();
  }

  for (int i = 0; i < v.size(); i++)
  {

    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    if (leftIndex < v.size())
    {
      v[i]->left = v[leftIndex];
    }
    else
    {
      v[i]->left = NULL;
    }
    if (rightIndex < v.size())
    {
      v[i]->right = v[rightIndex];
    }
    else
    {
      v[i]->right = NULL;
    }
  }
  return v[0];
}