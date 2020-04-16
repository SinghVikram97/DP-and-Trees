class Solution {
public:
    
    
    bool help(string s,vector<string> &wordDict,int start){
        
        
        if(start==s.length()){
            return true;
        }
        
        
        if(start>s.length()){
            return false;
        }
        
        // At each point match the string starting with startIndex with every word in wordDict
        
        for(int i=0;i<wordDict.size();i++){
            
            auto it=s.find(wordDict[i],start);
            
            if(it!=string::npos && it==start){
                
                if(help(s,wordDict,start+wordDict[i].length())){
                    return true;
                }
                else{
                    continue;
                }
                
            }
        }
        
        return false;

    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        return help(s,wordDict,0);
        
    }
};