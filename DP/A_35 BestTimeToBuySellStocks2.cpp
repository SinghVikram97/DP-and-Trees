
// O(N)
// Solution explaination
// https://drive.google.com/file/d/1r9D4szX2hCQYOfo0FKZu7A02_BE6tvSN/view
// Sell whenever prices becomes less than previous day
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int n = prices.size();

    if (n == 0 || n == 1)
    {
      return 0;
    }

    int total_profit = 0;

    int prevStock = -1;

    for (int i = 0; i < n - 1; i++)
    {

      if (prices[i + 1] > prices[i])
      {
        // Keep moving forward
        // If no stock(sold at prev step) buy
        if (prevStock == -1)
        {
          prevStock = prices[i];
        }
      }
      else
      {
        // Sell previous stock
        if (prevStock != -1)
        {
          total_profit += prices[i] - prevStock;
        }
        prevStock = -1;
      }
    }

    // Sell last stock
    if (prevStock != -1)
    {
      total_profit += prices[n - 1] - prevStock;
    }
    return total_profit;
  }
};