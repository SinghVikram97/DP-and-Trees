// https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1

void printCommon(Node *root1, Node *root2)
{
  stack<Node *> ms1;
  stack<Node *> ms2;

  Node *cur1 = root1;
  Node *cur2 = root2;

  while ((cur1 != NULL || !ms1.empty()) && (cur2 != NULL || !ms2.empty()))
  {

    while (cur1)
    {
      ms1.push(cur1);
      cur1 = cur1->left;
    }

    while (cur2)
    {
      ms2.push(cur2);
      cur2 = cur2->left;
    }

    cur1 = ms1.top();
    cur2 = ms2.top();

    if (cur1->data == cur2->data)
    {
      cout << cur1->data << " ";
      ms1.pop();
      ms2.pop();
      cur1 = cur1->right;
      cur2 = cur2->right;
    }
    else if (cur1->data < cur2->data)
    {
      ms1.pop();
      cur1 = cur1->right;
      cur2 = NULL; // IMP
    }
    else
    {
      ms2.pop();
      cur2 = cur2->right;
      cur1 = NULL; // IMP
    }
  }
}