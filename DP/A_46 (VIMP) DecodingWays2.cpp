// https://leetcode.com/problems/decode-ways-ii/
#define m 1000000007
#define ll long long int
class Solution
{
public:
  ll helper(string &s, int i, vector<ll> &dp)
  {

    if (i == s.length())
    {
      return 1;
    }

    if (dp[i] != -1)
    {
      return dp[i];
    }

    if (s[i] == '0')
    {
      return dp[i] = 0;
    }

    ll ans = 0;

    if (s[i] == '*')
    {

      // Take it single
      // 9 ways (1-9) so 9*(every possible combination for remaining string)
      ll add = ((9) * (helper(s, i + 1, dp) % m)) % m;

      ans = ans + add;

      // Take with next
      if (i + 1 < s.length())
      {

        // If next is a num
        if (s[i + 1] != '*')
        {

          ll num = s[i + 1] - '0';

          if (num >= 0 && num <= 6)
          {
            // *num
            // we can take * as (1-2) if num is 1,2,3,4,5,6 (num is fixed)
            // So 2 possible
            ans = ((ans % m) + ((2 * helper(s, i + 2, dp)) % m)) % m;
          }
          else if (num > 6 && num <= 9)
          {
            // we can take * as only 1 if num>6 as alphabets upto 26, 27 invalid
            // So only 1 possible
            ans = ((ans % m) + (helper(s, i + 1, dp) % m)) % m;
          }
        }
        // Next is also *
        else
        {
          // **
          // If we take 1st * as 1 then 2nd * as (1-9)=9 ways
          // If we take 1st * as 2 then 2nd * as (1-6)=6 ways
          // Can't take 1st * as >=3
          // So total 15 ways
          ans = ((ans % m) + ((15 * helper(s, i + 2, dp)) % m)) % m;
        }
      }
    }
    else
    {

      // Take single
      if (s[i] - '0' > 0)
      {
        ans = ((ans % m) + (helper(s, i + 1, dp) % m)) % m;
      }

      // Take with next
      if (i + 1 < s.length())
      {

        // If next is not *
        if (s[i + 1] != '*')
        {

          int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

          if (num >= 10 && num <= 26)
          {
            ans = ((ans % m) + (helper(s, i + 2, dp) % m)) % m;
          }
        }
        else
        {

          // Next is *
          if (s[i] - '0' == 1)
          {
            ans = ((ans % m) + ((9 * helper(s, i + 2, dp)) % m)) % m;
          }
          else if (s[i] - '0' == 2)
          {
            ans = ((ans % m) + ((6 * helper(s, i + 2, dp)) % m)) % m;
          }
        }
      }
    }
    dp[i] = ans % m;

    return dp[i];
  }

  int numDecodings(string s)
  {

    int n = s.length();

    if (n == 0)
      return n;

    vector<ll> dp(n + 1, -1);

    return helper(s, 0, dp);
  }
};