// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution
{
  unordered_map<int, string> mp;

public:
  Solution()
  {
    mp[2] = "abc";
    mp[3] = "def";
    mp[4] = "ghi";
    mp[5] = "jkl";
    mp[6] = "mno";
    mp[7] = "pqrs";
    mp[8] = "tuv";
    mp[9] = "wxyz";
  }

  vector<string> help(string digits, int index)
  {

    int n = digits.length();
    if (index == n)
    {
      // Empty string vector
      return {""};
    }

    int num = digits[index] - '0';

    vector<string> next = help(digits, index + 1);

    // Can select any character from given number's string

    vector<string> finalAns;

    for (int i = 0; i < mp[num].length(); i++)
    {
      string temp = "";
      for (int j = 0; j < next.size(); j++)
      {
        temp = mp[num][i] + next[j];
        finalAns.push_back(temp);
      }
    }

    return finalAns;
  }

  vector<string> letterCombinations(string digits)
  {
    int n = digits.length();
    if (n == 0)
    {
      return {};
    }
    return help(digits, 0);
  }
};