class Solution {
public:
    int check(vector<int> &coins,int amount,int i,vector<vector<int>> &dp) {
        if(i<0) return 0;
        if(amount==0) return 1;
if(dp[i][amount]!=-1) return dp[i][amount];
 int take=0;
     if(amount>=coins[i]) {
    take=check(coins,amount-coins[i],i,dp);
     }


    int not_take=(i>0)?check(coins,amount,i-1,dp):0;
    

    return dp[i][amount]=take+not_take;

}
    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return check(coins,amount,coins.size()-1,dp);
    }
};