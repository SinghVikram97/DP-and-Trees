// https://www.geeksforgeeks.org/printing-longest-common-subsequence/
class Solution
{
public:
  int help(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
  {

    int n1 = s1.length();
    int n2 = s2.length();

    if (i == n1 || j == n2)
    {
      return 0;
    }

    if (dp[i][j] == -1)
    {

      if (s1[i] == s2[j])
      {
        dp[i][j] = 1 + help(s1, s2, i + 1, j + 1, dp);
      }

      else
      {
        dp[i][j] = max(help(s1, s2, i + 1, j, dp), help(s1, s2, i, j + 1, dp));
      }
    }

    return dp[i][j];
  }

  string longestCommonSubsequence(string text1, string text2)
  {

    int n1 = text1.length();
    int n2 = text2.length();

    vector<vector<int>> dp(n1, vector<int>(n2));

    for (int i = 0; i < n1; i++)
    {
      for (int j = 0; j < n2; j++)
      {
        dp[i][j] = -1;
      }
    }

    help(text1, text2, 0, 0, dp);

    int i = 0, j = 0;
    string ans = "";
    while (i < n1 && j < n2)
    {

      if (text1[i] == text2[j])
      {
        ans = ans + text1[i];
        i++;
        j++;
      }
      else
      {

        if (i + 1 < n1 && j + 1 < n2)
        {
          // Move to max side
          if (dp[i + 1][j] > dp[i][j + 1])
          {
            // Move down
            i++;
          }
          else
          {
            // Move right
            j++;
          }
        }
        else if (i + 1 >= n1)
        {
          j++;
        }
        else if (j + 1 >= n2)
        {
          i++;
        }
      }
    }
    return ans;
  }
};