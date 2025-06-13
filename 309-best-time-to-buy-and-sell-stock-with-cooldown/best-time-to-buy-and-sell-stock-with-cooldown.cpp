class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));
  dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i=prices.size()-1; i>=0; i--) {
            for(int j=0; j<2; j++) {
                   
         int buy=0;
     if(!j) {
         buy=-prices[i]+dp[i+1][1];
    }  int sell=0; 
     if(j) {
         sell=prices[i]+dp[i+2][0];
            
        }int not_did =dp[i+1][j];
         dp[i][j]=max({buy,sell,not_did});}}
        return dp[0][0];
        
    }
};