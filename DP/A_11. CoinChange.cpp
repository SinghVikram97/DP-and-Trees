// https://leetcode.com/problems/coin-change

// Recursion

class Solution
{
public:
  int help(vector<int> &coins, int amount, int index)
  {

    int n = coins.size();

    if (amount == 0)
    {
      return 0;
    }

    if (amount < 0)
    {
      return INT_MAX - 5;
    }

    if (index == n)
    {
      return INT_MAX - 5;
    }

    // Can take unlimited no of coins at this index

    // Take or don't take
    return min(1 + help(coins, amount - coins[index], index), help(coins, amount, index + 1));
  }

  int coinChange(vector<int> &coins, int amount)
  {

    int ans = help(coins, amount, 0);

    if (ans == INT_MAX - 5)
    {
      return -1;
    }
    else
    {
      return ans;
    }
  }
};

// Recursion + Memo

class Solution {
public:
    
    
    int help(vector<int> &coins,int amount,int index,vector<vector<int> > &dp){
        
        int n=coins.size();
        
        if(amount==0){
            return 0;
        }
        
        if(amount<0){
            return INT_MAX-5;
        }
        
        if(index==n){
            return INT_MAX-5;
        }
        
        if(dp[index][amount]==-1){
            
            
            // Can take unlimited no of coins at this index
        
            // Take or don't take
            dp[index][amount]=min(1+help(coins,amount-coins[index],index,dp),help(coins,amount,index+1,dp));     
            
        }
        
        return dp[index][amount];
        
        
           
        
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        
       int n=coins.size();      
        
       vector<vector<int> > dp(n+1,vector<int>(amount+1));
        
       for(int i=0;i<=n;i++){
           for(int j=0;j<=amount;j++){
               dp[i][j]=-1;
           }
       } 
        
       int ans=help(coins,amount,0,dp);
        
       
        
       if(ans==INT_MAX-5){
           return -1;
       } 
        else{
           return ans;
        }
    
    }
};