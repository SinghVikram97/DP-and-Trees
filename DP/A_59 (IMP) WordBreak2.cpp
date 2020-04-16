// https://leetcode.com/problems/word-break-ii/
// Basic recursion
class Solution
{
public:
  void help(string s, vector<string> &wordDict, int start, string temp, vector<string> &ans)
  {

    if (start == s.length())
    {

      // push temp to ans

      // To remove extra space at the end
      temp.pop_back();

      ans.push_back(temp);

      return;
      // return true;
    }

    if (start > s.length())
    {
      // Not possible return
      return;
    }

    // At each point match the string starting with startIndex with every word in wordDict

    for (int i = 0; i < wordDict.size(); i++)
    {

      auto it = s.find(wordDict[i], start);

      // If word matches string begining from start of the string
      if (it != string::npos && it == start)
      {

        // Match remaining string ie. start+wordLength remains

        // Directly pass temp+wordDict[i]+" " to avoid backtracking later
        help(s, wordDict, start + wordDict[i].length(), temp + wordDict[i] + " ", ans);
      }
    }

    return;
  }

  vector<string> wordBreak(string s, vector<string> &wordDict)
  {
    int n = s.length();

    vector<string> ans;

    help(s, wordDict, 0, "", ans);

    return ans;
  }
};

// Recursion with return value
class Solution
{
public:
  vector<string> help(string s, vector<string> &wordDict, int start)
  {

    int n = s.length();

    if (start == n)
    {
      return {""};
    }

    vector<string> ans;

    for (int i = 0; i < wordDict.size(); i++)
    {

      auto it = s.find(wordDict[i], start);

      if (it != string::npos && it == start)
      {

        vector<string> temp = help(s, wordDict, start + wordDict[i].length());

        for (int k = 0; k < temp.size(); k++)
        {

          temp[k] = temp[k] != "" ? wordDict[i] + " " + temp[k] : wordDict[i];
        }

        ans.insert(ans.end(), temp.begin(), temp.end());

        continue;
      }
    }

    return ans;
  }

  vector<string> wordBreak(string s, vector<string> &wordDict)
  {
    int n = s.length();

    return help(s, wordDict, 0);
  }
};

// DP with memo
class Solution
{
    
    // Maps index (start index) to vector<string> it returns
    unordered_map<int,vector<string> > mp;
    
public:
    
    vector<string> help(string s,vector<string> &wordDict,int start){
        
        
        int n=s.length();
        
        if(start==n){
            return {""};
        }
        
        // Memoization        
        if(mp.find(start)!=mp.end()){
            return mp[start];
        }
        
        vector<string> ans;
        
        for(int i=0;i<wordDict.size();i++){

            auto it=s.find(wordDict[i],start);
            
            if(it!=string::npos && it==start){
                
                vector<string> temp=help(s,wordDict,start+wordDict[i].length());
                
                for(int k=0;k<temp.size();k++){
                    
                    temp[k]= temp[k] != "" ? wordDict[i]+" "+temp[k] :  wordDict[i];
                    
                }
                
                ans.insert(ans.end(),temp.begin(),temp.end());
                
                continue;
                
            }
        
        }
        
        mp[start]=ans;
        
        return mp[start];
        
    }
    
    
    
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        
        return help(s, wordDict, 0);

    }
};