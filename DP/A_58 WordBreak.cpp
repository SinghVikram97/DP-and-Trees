// https://leetcode.com/problems/word-break/
class Solution
{
public:
  bool help(string s, vector<string> &wordDict, int start, vector<int> &dp)
  {

    if (start == s.length())
    {
      return true;
    }

    if (start > s.length())
    {
      return false;
    }

    if (dp[start] != -1)
    {
      return dp[start];
    }

    // At each point match the string starting with startIndex with every word in wordDict

    for (int i = 0; i < wordDict.size(); i++)
    {

      auto it = s.find(wordDict[i], start);

      // If word matches string begining from start of the string
      if (it != string::npos && it == start)
      {

        // Match remaining string ie. start+wordLength remains
        if (help(s, wordDict, start + wordDict[i].length(), dp))
        {
          dp[start] = 1;
          return dp[start];
        }
        // If false try another word
        else
        {
          continue;
        }
      }
    }

    // Not possible return false
    dp[start] = 0;
    return dp[start];
  }

  bool wordBreak(string s, vector<string> &wordDict)
  {

    int n = s.length();

    vector<int> dp(n + 1, -1);

    return help(s, wordDict, 0, dp);
  }
};