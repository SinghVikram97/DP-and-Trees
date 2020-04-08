// https://leetcode.com/problems/decode-ways/
class Solution
{
public:
  int helper(string &s, int i, vector<int> &dp)
  {

    int n = s.length();

    if (i == n)
    {
      return 1;
    }

    if (dp[i] == -1)
    {

      // Either take single digit or can take double if >=10 & <=26

      int ans = 0;

      // Take single
      if (s[i] - '0' > 0)
      {
        ans += helper(s, i + 1, dp);
      }

      // Take with next combined
      if (i + 1 < n)
      {

        int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

        if (num >= 10 && num <= 26)
        {
          ans += helper(s, i + 2, dp);
        }
      }

      dp[i] = ans;
    }

    return dp[i];
  }

  int numDecodings(string s)
  {

    int n = s.length();
    if (n == 0)
      return n;

    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++)
    {
      dp[i] = -1;
    }

    return helper(s, 0, dp);
  }
};