// https://leetcode.com/problems/palindrome-partitioning/

class Solution
{
public:
  bool isPalindrome(string str)
  {

    int s = 0;
    int e = str.length() - 1;

    while (s <= e)
    {
      if (str[s] != str[e])
      {
        return false;
      }
      s++;
      e--;
    }

    return true;
  }

  void help(string &s, int startIndex, vector<string> ans, vector<vector<string>> &finalAns)
  {

    int n = s.length();

    if (startIndex == n)
    {
      // Push it to final ans
      finalAns.push_back(ans);
      return;
    }

    // Try starting at each point from startIndex to end
    string temp = "";
    for (int i = startIndex; i < n; i++)
    {

      temp = temp + s[i];

      if (isPalindrome(temp))
      {

        // Push it to ans
        ans.push_back(temp);
        help(s, i + 1, ans, finalAns);

        // Backtrack
        ans.pop_back();
      }
    }

    return;
  }

  vector<vector<string>> partition(string s)
  {

    vector<vector<string>> finalAns;

    vector<string> ans;

    help(s, 0, ans, finalAns);

    return finalAns;
  }
};