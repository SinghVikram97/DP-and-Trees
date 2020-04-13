// https://leetcode.com/problems/candy/
// https://www.geeksforgeeks.org/temple-offerings/
class Solution
{
public:
  int candy(vector<int> &ratings)
  {

    int n = ratings.size();

    vector<int> ans(n, 1);

    // Traverse from left and make sure each child gets more than it's left if rating is higher
    for (int i = 1; i < n; i++)
    {
      if (ratings[i] > ratings[i - 1])
      {
        ans[i] = ans[i - 1] + 1;
      }
    }

    // Traverse from right and make sure each child gets more than it's right if rating is higher
    for (int i = n - 1; i > 0; i--)
    {
      if (ratings[i - 1] > ratings[i] && ans[i - 1] <= ans[i])
      {
        ans[i - 1] = 1 + ans[i];
      }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += ans[i];
    }

    return sum;
  }
};