class Solution {
public:


    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
           for(int i=prices.size()-1; i>=0; i--) {
            for(int j=0; j<2; j++) {
                for(int k=0; k<=2; k++) {
                    int profit=0;
                    if(!j) {
            int buy_1=-prices[i]+dp[i+1][1][k]; 
            int not_buy=dp[i+1][0][k]; 
            dp[i][j][k]=max(buy_1,not_buy);
          
        }
        if(j) {
           if(k<2) {
            int sell=prices[i]+dp[i+1][0][k+1];
            int not_sell=dp[i+1][1][k];
            profit=max(sell,not_sell);
            dp[i][j][k] = profit;}
            else {
 dp[i][j][k] = dp[i + 1][1][k];
            }
           
        }

                }
            }
           }
        return dp[0][0][0];
        
    }
};