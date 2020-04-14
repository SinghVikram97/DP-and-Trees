// https://leetcode.com/problems/wiggle-subsequence/

// O(n^2)

class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {

    int n = nums.size();

    if (n <= 1)
    {
      return n;
    }

    // nums[i], (-1,0,1)
    // -1 matlab last niche gya, 1 matlab last upar gaya
    vector<pair<int, int>> dp(n);

    dp[0] = make_pair(1, 0);

    if (nums[1] == nums[0])
    {
      dp[1] = make_pair(1, 0);
    }
    else
    {
      dp[1] = nums[1] > nums[0] ? make_pair(2, 1) : make_pair(2, -1);
    }

    for (int i = 2; i < n; i++)
    {

      dp[i].first = 1;
      dp[i].second = 0;

      for (int j = i - 1; j >= 0; j--)
      {

        // nums[i] nums[j] se bada hai toh nums[j] pe subsequence niche girni chaiye
        if (nums[i] > nums[j] && (dp[j].second == -1 || dp[j].second == 0))
        {

          if (dp[i].first < 1 + dp[j].first)
          {
            dp[i].first = 1 + dp[j].first;
            dp[i].second = 1;
          }
        }

        else if (nums[i] < nums[j] && (dp[j].second == 1 || dp[j].second == 0))
        {
          if (dp[i].first < 1 + dp[j].first)
          {
            dp[i].first = 1 + dp[j].first;
            dp[i].second = -1;
          }
        }
        else
        {
          // Both equal do nothing
        }
      }
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
      ans = max(ans, dp[i].first);
    }
    return ans;
  }
};

// O(N) time O(N) space
class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {

    int n = nums.size();

    if (n <= 1)
    {
      return n;
    }

    vector<int> up(n);   // longest wiggle ending upwards at i
    vector<int> down(n); // longest wiggle ending downwards at i

    up[0] = 1;
    down[0] = 1;

    for (int i = 1; i < n; i++)
    {

      if (nums[i] > nums[i - 1])
      {
        // Nums[i] bada hai
        // to jha down end hua i-1 + 1 is up[i]
        up[i] = 1 + down[i - 1];

        // down same rhega
        down[i] = down[i - 1];
      }
      else if (nums[i] < nums[i - 1])
      {
        down[i] = 1 + up[i - 1];
        up[i] = up[i - 1];
      }
      else
      {
        down[i] = down[i - 1];
        up[i] = up[i - 1];
      }
    }

    return max(down[n - 1], up[n - 1]);
  }
};

// O(N) time and O(1) space
class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {

    int n = nums.size();

    if (n <= 1)
    {
      return n;
    }

    int up = 1;
    int down = 1;

    for (int i = 1; i < n; i++)
    {

      if (nums[i] > nums[i - 1])
      {
        up = 1 + down;
      }
      else if (nums[i] < nums[i - 1])
      {
        down = 1 + up;
      }
      else
      {
        // do nothing
      }
    }

    return max(down, up);
  }
};