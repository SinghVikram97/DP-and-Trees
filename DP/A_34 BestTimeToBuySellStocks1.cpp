// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// O(n^2)
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int n = prices.size();
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (prices[j] > prices[i])
        {
          ans = max(ans, prices[j] - prices[i]);
        }
      }
    }
    return ans == -1 ? 0 : ans;
  }
};
// O(n)
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int n = prices.size();
    if (n == 0)
      return 0;
    int ans = 0;
    int cur_min = prices[0];

    for (int i = 1; i < n; i++)
    {

      if (prices[i] > cur_min)
      {
        ans = max(ans, prices[i] - cur_min);
      }
      else
      {
        cur_min = prices[i];
      }
    }
    return ans;
  }
};